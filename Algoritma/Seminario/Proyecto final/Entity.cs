/*
 * Created by SharpDevelop.
 * User: David Gutierrez
 * Date: 29/05/2020
 * Time: 02:41 p. m.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Drawing;
using System.Collections.Generic;

namespace ProyectPreyPredator {
	
	public class Entity {
		static public Graph graph;
		protected int id;
		protected int origen;
		protected int posInit;
		protected int destino;
		protected int img;
		protected int size;
		protected List<Point> path;
		
		public Entity(){ }
		
		public Entity(Point p, int origen, int destino, int size) {
			path = new List<Point>();
			path.Add(p);
			this.size = size;
			this.img = 4;
			this.origen = origen;
			this.destino = destino;
		}
		
		//getters
		public int Id		{ get { return id; } }
		public int Origen	{ get { return origen; } }
		public int Destino	{ get { return destino; } }
		public int Img		{ get { return img; } }
		public int PosInit	{ get { return posInit; } set { posInit = value; } }
		public int Size		{ get { return size; } set { size = value; } }
		public List<Point> Path { get { return path;  } }
		
		public float distance(Entity p) {
			int thisPos = 0, pos = 0;
			return (float)Math.Sqrt(Math.Pow(Math.Abs(p.path[pos].X - this.path[thisPos].X), 2) + Math.Pow(Math.Abs(p.path[pos].Y - this.path[thisPos].Y), 2));
		}
		
		public float distance(Point p) {
			return (float)Math.Sqrt(Math.Pow(Math.Abs(p.X - this.path[Prey.Position].X), 2) + Math.Pow(Math.Abs(p.Y - this.path[Prey.Position].Y), 2));
		}
		
		public bool collision(Entity p, int range) {
			return range > distance(p);
			//45 comer
			//180 radar
		}
		
		public bool collision(Point p, int range) {
			return range > distance(p);
			//45 comer
			//180 radar
		}
		
		public bool inEdge(Entity e) {
			return ((origen == e.origen && destino == e.destino) || (origen == e.destino && destino == e.origen));
		}
		
	}
	
	public class Predator: Entity {
		static private int index = -1;//crea los id de cada depredador
		static private int speed = 10;//todas las presas tienen la misma velocidad inicial
		static private int position = 0;
		private Prey prey;	//presa a la que sigue
		private int euforia;//nivel de euforia (aumenta al comer una presa)
		
		public Predator() {}
		
		public Predator(int origen, int size, Point p) {
			this.id = ++index;
			this.size = size;
			this.prey = null;
			euforia = 0;
			img = 0;
			this.posInit = this.destino = this.origen = origen;
			path = new List<Point>();
			path.Add(p);
		}
		
		public Prey Prey			{ get { return prey; } }
		public int Euforia			{ get { return euforia; } set {euforia = value; } }
		public static int LastIndex { get { return index; } }
		public static int Speed		{ get { return speed; } set { speed = value; } }
		public static int Position	{ get { return position; }  }
		
		public void addRoadRandom() {
			/*moverse a partir del origen*/
			Edge e;
			//busca una proxima ruta, intentando evitar la ya recorrida anteriormente
			if((e = graph.Vertexs[destino].edgeRandom()).Destino.Id == origen) { e = graph.Vertexs[destino].edgeRandom(); }
			
			path.AddRange(e.Path);	//agrego la ruta a seguir
			origen = destino;		//obtengo mi nuevo origen
			destino = e.Destino.Id;	//obtengo mi nuevo destino
		}
		
		public void followPrey() {
			//seguir presa si esta en su camino
			List<Edge> le = graph.Vertexs[destino].Edges;
			
			foreach(Edge e in le) {
				if(e.Destino.Id == prey.Destino ||
				   (destino == prey.Destino && e.Destino.Id == prey.Origen)) {
					//si conoce el destino de la presa seguirla o
					//si conoce el origen de la presa seguirla
					//y si destino es donde esta de depredador
					path.AddRange(e.Path);	//agrego la ruta a seguir
					origen = destino;		//obtengo mi nuevo origen
					destino = e.Destino.Id;	//obtengo mi nuevo destino
					return;
				}
			}
			/*si no puede seguir a la presa continua su movimiento random*/
			addRoadRandom();
		}
		
		public void newPrey(Prey p) {
			prey = p;
		}
		
		public bool containPrey() {
			return prey != null;
		}
		
		public override string ToString() {
			return string.Format("Depredador(id: {0}, presa: {1}, origen: {2}, euforia: {3})", id, containPrey() ? "Si" : "No", origen, euforia);
			//Depredador(id: 1, presa: No, origen: 1)
		}
	}
	
	public class Prey: Entity {
		static private List<Edge> edges;
		static private List<List<Vertex>> roads;
		static private List<float> distances;
		static private int index = -1;
		static private Random random = new Random();
		static private int speed = 8;
		static private int position = 0;
		static private int deads = 0;
		public Predator predator;
		public int survivor_speed;
		public bool goal, start, isInDenger;//esta en peligro
		public bool invisible;
		public bool dead;
		public bool outScreen;
		
		public Prey() { }
		
		public Prey(int origen, int size, Point p) {
			this.id		= ++index;
			this.size	= size;
			this.img	= random.Next(4, 10)*2;
			predator	= null;
			path		= new List<Point>();
			survivor_speed = 0;
			this.posInit = this.destino = this.origen = origen;
			dead = outScreen = invisible = isInDenger = start = goal = false;
			path.Add(p);
		}
		
		//gettes
		public static int LastIndex		{get { return index; } }
		public static List<Edge> Edges	{ set { edges = value; } }
		public static int Speed			{ get { return speed; } set { speed = value; } }
		public static int Position		{ get { return position; } set {position = value; } }
		public static int Deads			{ get { return deads; } set { deads = value; } }
		//public int LastPosition			{ get { return lastPosition; } set { lastPosition = value; } }
		
		static public void to_roads(List<List<Vertex>> _roads, List<float> _pesos) {
			roads = _roads;
			distances = _pesos;
		}
		
		public void addRoad() {
			//toma la mejor decicion para moverse
			moveDesicion();
			
			if(origen == destino) {
				//llego a la meta
				goal = true;
				return;
			}
			//genero camino
			Edge e;
			e = graph.Vertexs[origen].getEdge(destino);
			//agrega la ruta a trazar
			path.AddRange(e.Path);
		}
		
		private void moveDesicion() {
			if(isInDenger) {
				//si se encuentra en peligro cambio de direccion (retroceder)
				int aux = origen;
				origen = destino;
				destino = aux;
				//al cambiar su direcion dejara de estar en peligro
				isInDenger = false;
				//busca un nuevo mejor destino
				searchDestiny();
				//buscar proximo destino mas sercano
			} else {
				//si no esta en peligro
				if(start) {
					//origen cambia al siguiente
					origen = destino;
				}
				start = true;
				/*busco nuevo destino*/
				destino = roads[origen][1].Id;
			}
			
			if(invisible) {
				//quita la invisibilidad
				invisible = false;
				survivor_speed = 0;
			}
		}
		
		public void returnRoad() {	
			//toma decicion de regresar a la mitad del camino
			int count = path.Count;
			/*añado proximo camino*/
			path.AddRange(graph.Vertexs[destino].getEdge(origen).Path);
			/*remuevo el camino anterior*/
			path.RemoveRange(0, count*2);
			//cmabio su origen y destino
			int aux = origen;
			origen = destino;
			destino = aux;
		}
		
		public bool changeToRoad() {
			/*se debe cambiar de ruta*/
			if(distances[origen] < distances[destino] && path.Count > 1) {
				return true;
			}
			return false;
		}
		
		public void addRoadDead(List<Point> p) {
			/*remuevo el camino restante*/
			path.Clear();
			/*añado proximo camino*/
			path.AddRange(p);
			//ya ha muerto
			dead = true;
		}
		
		public void runAway() {
			//caso 1.- no hay necesidad del cambio de ruta
			//caso 2.- regresar al vertice anterior
			//caso 2.1.- regreso al vertice anterior y aun lo presiguen, entonces buscar la siguente arista mas secarna al destino
			
			if(origen == destino) { return; }
			
			//casos (2 y 2.1)
			if((predator.Origen == destino && predator.Destino == origen) ||//presa y predador se ven de frente en la misma arista
			   (predator.Destino == destino && predator.Origen != origen) ||//presa y predador en diferentes aristas pero se dirijen al mismo vertice
			   (predator.Origen == origen && predator.Destino == destino && predator.Path.Count < path.Count) ) {//predador esta delante de presa y presa lo sigue
				
				//caso 2.1
				if(predator.Origen == destino && predator.Destino == origen) {
					/*despues de regresar al vertice anterior debe buscar otro vertice*/
					isInDenger = true;
				}
				returnRoad();
			}
			
		}
		
		private void searchDestiny() {
			int mejor_opcion = -1;
			double peso = double.MaxValue;
			foreach(Edge e in roads[origen][0].Edges) {
				if(distances[e.Destino.Id] < peso && e.Destino.Id != destino) {
					mejor_opcion = e.Destino.Id;
					peso = distances[e.Destino.Id];
				}
			}
			//ternario para decidir si el mejor destino se cambia o sigue siendo su destino actual
			destino = mejor_opcion == -1 ? destino : mejor_opcion;
		}
		
		public void newPredator(Predator p) {
			predator = p;
		}
		
		public bool containPredator() {
			return predator != null;
		}
	
		public override string ToString() {
			return String.Format("Presa(id: {0}, depredador: {1}, origen: {0})", id, containPredator() ? "Si" : "No", origen);
			//Presa(id: 1, depredador: Si, origen: 5)
		}

	}

}
