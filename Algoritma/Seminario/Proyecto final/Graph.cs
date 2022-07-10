/*
 * Creado por SharpDevelop.
 * Usuario: david
 * Fecha: 12/02/2020
 * Hora: 10:42 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
using System;
using System.Drawing;
using System.Collections.Generic;

namespace ProyectPreyPredator {
	/// <summary>
	/// Description of Graphic.
	/// </summary>
	public class Edge { /*arista*/
		static private int index = -1;
		private Vertex origen;
		private Vertex destino;
		private int id;
		private double weight;
		private List<Point> path;
		
		//Getters
		public Vertex Origen  { get { return origen;  } }
		public Vertex Destino { get { return destino; } }
		public int Id         { get { return id;      } }
		public double Weight  { get { return weight;  } }
		public List<Point> Path { get { return path;  } }
		
		public Edge(Vertex v1, Vertex v2, double Weight, List<Point> listp) {
			this.id      = ++index;
			this.origen  = v1;
			this.destino = v2;
			this.weight  = Weight;
			path         = new List<Point>(listp);
		}

		public Edge() { }
		
		
		public int CompareTo(Edge e) {
			return this.Weight.CompareTo(e.Weight);
		}
	}
		
	public class Vertex { 
		static private int index = -1;
		private List<Edge> ListEdge;
		private List<int> subGrafo;
		private Figure circle;
		private int id;//from 1 to n
		
		//Getters
		public List<int> SubGrafo { get { return subGrafo; } set { subGrafo = value; } }
		public List<Edge> Edges	  { get { return ListEdge; } }
		public Figure Circle      { get { return circle;   } }
		public int Id             { get { return id;       } }
		
		public Vertex() { this.subGrafo = new List<int>(); }
		
		public Vertex(Figure c) {
			this.id       = ++index;
			this.circle   = c;
			this.ListEdge = new List<Edge>();
			this.subGrafo = new List<int>();
		}
		
		public Vertex(Vertex v) {
			this.id     = v.id;
			this.circle = v.circle;
			this.ListEdge = v.Edges;
			this.subGrafo = v.subGrafo;
		}
		
		public void addEdge(Edge e) {
			this.ListEdge.Add(e);
		}
		
		public Edge getEdge(int destino) {
			/*regresa la arista que conecta con el vertice destino*/
			foreach(Edge e in ListEdge) {
				if(e.Destino.Id == destino) {
					return e;
				}
			}
			return null;
		}
		
		public Edge edgeRandom() {
			/*regresa una arista random*/
			Random random = new Random();
			return ListEdge[random.Next(0, ListEdge.Count)];
		}
	
		public override String ToString() {
			return String.Format("{0}.- (X: {1}, Y: {2}, R: {3})", id, circle.X, circle.Y, circle.R);
		}
	}
		
	public class Graph {
		private List<Vertex> listVertex;
		
		public Graph() {
			listVertex = new List<Vertex>();
		}
		
		public Graph(Graph g) {
			listVertex = new List<Vertex>(g.listVertex);
		}
		
		~Graph() { Clear(); }
		
		public void Copy(Graph g) {
			this.listVertex.AddRange(g.listVertex);
		}
		
		public List<Vertex> Vertexs {get { return listVertex; } }

		public void addVertex(Vertex v) {
			listVertex.Add(v);
		}
		
		public void addVertex(Figure circle) {
			//cada nuevo circulo que entre se agregara al grafo
			listVertex.Add(new Vertex(circle));
		}
		
		public void addEdge(int i, int j, float weight, List<Point> listp) {
			listVertex[i].addEdge(new Edge(listVertex[i], listVertex[j], weight, listp));
		}
		
		public void addEdge(Edge e) {
			listVertex[e.Origen.Id].addEdge(e);
		}
		
		public void Clear() {
			listVertex.Clear();
		}
		
		
		public List<Edge> getEdges() {
			List<Edge> edges = new List<Edge>();
			foreach(Vertex v in listVertex) {
				edges.AddRange(v.Edges);
			}
			return edges;
		}
		
	}

}
