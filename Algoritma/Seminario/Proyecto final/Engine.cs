/*
 * Created by SharpDevelop.
 * User: David Gutierrez
 * Date: 09/06/2020
 * Time: 07:54 p. m.
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;

namespace ProyectPreyPredator {
	
	public class Engine {
		static private Pen inRange = new Pen(Color.Red, 1), notRange = new Pen(Color.Blue, 1);
		static private Brush brush = new SolidBrush(Color.Red);
		private Bitmap canvas;
		private Bitmap canvasSave;
		private List<Entity> cherrys;
		private Entity dead_cherry;
		private List<Prey> preys;
		private List<Predator> predators;
		private List<Bitmap> images;
		private Figure destiny;
		private Font font;
		private SolidBrush brocha;
		private int img;
		private Prey goal;
		private bool start;
		private int preyPosition;
		private int predatorPosition;
		
		public Engine(Bitmap canvas) {
			this.canvas = canvas;
			this.images = new List<Bitmap>();
			this.font	= new Font("Arial", 17);
			this.brocha = new SolidBrush(Color.Black);
			this.dead_cherry = null;
			this.destiny = null;
			this.cherrys =	new List<Entity>();
			this.Preys =	new List<Prey>();
			this.predators =new List<Predator>();
			this.start = false;
			this.preyPosition = 0;
			this.predatorPosition = 0;
			loadImages();
		}
		
		public Bitmap Canvas { get { return canvas; } set { canvas = value; }}
		public Bitmap CanvasSave { get { return canvasSave; } set { canvasSave = value; }}
		public List<Entity> Cherrys { get { return cherrys; } set { cherrys = value; } }
		public Figure Destiny { get { return destiny; } set { destiny = value; } }
		public List<Prey> Preys { get { return preys; } set {preys = value; } }
		public List<Predator> Predators { get { return predators; } set { predators = value; } }
		public bool Start { get { return start; } set { start = value; } }
		
		private void loadImages() {
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 10; j++) {
					images.Add(new Bitmap(@"images/sprites/sprite_"+ i + j + ".png"));
				}
			}
		}
		
		public void ActualizePosition() {
			foreach(Prey prey in preys) {
				prey.Path.RemoveRange(0, Prey.Speed+prey.survivor_speed < prey.Path.Count ? Prey.Speed+prey.survivor_speed : prey.Path.Count-1);
			}
			preyPosition += Prey.Speed;
			foreach(Predator predator in Predators) {
				predator.Path.RemoveRange(0, Predator.Speed < predator.Path.Count ? Predator.Speed : predator.Path.Count-1);
			}
			predatorPosition += Predator.Speed;
		}
		
		public void drawing(bool clear = true) {
			//dibujo todos los depredadores, presas y cherrys
			Graphics g;
			if(clear) {			
				g = Graphics.FromImage(canvas);
				g.Clear(Color.Transparent);
			} else {		
				g = Graphics.FromImage(canvasSave);
			}
			
			if(destiny != null) {
				g.FillEllipse(brush, destiny.X-30, destiny.Y-30, 60, 60);
			}
			
			foreach(Entity sprite in cherrys) {
				//dibujo cherry
				g.DrawImage(images[sprite.Img], sprite.Path[0].X-(int)(sprite.Size/2), sprite.Path[0].Y-(int)(sprite.Size/2), sprite.Size, sprite.Size);
			}
			
			foreach(Prey sprite in preys) {
				if(sprite.dead && !sprite.outScreen) {
					if(sprite.collision(new Point(1,30) , 35)) {
						sprite.outScreen = true;
						Prey.Deads++;
						continue;
					}
					g.DrawImage(images[5],										//imagen
					           	sprite.Path[Prey.Position].X-(int)(sprite.Size/2),	//x
				       			sprite.Path[Prey.Position].Y-(int)(sprite.Size/2),	//y
					            sprite.Size, sprite.Size);	
					continue;
				}
				if(Prey.Position > sprite.Path.Count || sprite.outScreen) {
					continue;
				}
				//obtengo la imagen de la presa a mostrar
				img =	preyPosition%(Prey.Speed*3)==0 || preyPosition%(Prey.Speed*4)==0
								? sprite.containPredator() ? 6 : sprite.Img		
								: sprite.containPredator() ? 7 : sprite.Img+1;
				img =	sprite.invisible ? 5 : img;
				//dibujo presa
				int i = Prey.Position;
				g.DrawImage(	images[img],										//imagen
					           	sprite.Path[Prey.Position].X-(int)(sprite.Size/2),	//x
				       			sprite.Path[Prey.Position].Y-(int)(sprite.Size/2),	//y
					            sprite.Size, sprite.Size);							//ancho, alto
				//dibujo id
				g.DrawString(sprite.Id.ToString(), font, brocha, sprite.Path[Prey.Position].X-22, sprite.Path[Prey.Position].Y+7);
			}
			
			foreach(Predator sprite in predators) {
				if(Predator.Position > sprite.Path.Count) {
					continue;
				}
				if(sprite.Prey != null && Prey.Position > sprite.Prey.Path.Count) {
					continue;
				}
				//obtengo la imagen del depredador a mostrar
				img =	predatorPosition%(Predator.Speed*3)==0 || predatorPosition%(Predator.Speed*4)==0
						? sprite.containPrey() ? sprite.Img+2 : sprite.Img
						: sprite.containPrey() ? sprite.Img+3 : sprite.Img+1;
				//dibujo depredador
				g.DrawImage(	images[img],											//imagen
					           	sprite.Path[Predator.Position].X-(int)(sprite.Size/2),	//x
				       			sprite.Path[Predator.Position].Y-(int)(sprite.Size/2),	//y
					            sprite.Size, sprite.Size);								//ancho, alto
				//dibujo id
				g.DrawString(sprite.Id.ToString(), font, brocha, sprite.Path[Predator.Position].X-22, sprite.Path[Predator.Position].Y+7);
				
				g.DrawEllipse(sprite.containPrey() ? inRange : notRange, sprite.Path[Predator.Position].X-150, sprite.Path[Predator.Position].Y-150, 300, 300);
					
				if(sprite.containPrey()) {
					g.DrawLine(inRange, sprite.Path[Predator.Position].X, sprite.Path[Predator.Position].Y, sprite.Prey.Path[Prey.Position].X, sprite.Prey.Path[Prey.Position].Y);
				}
			}
			
			g.Dispose();
		}
		
		public void removeSave() {
			Graphics g = Graphics.FromImage(canvasSave);
			g.Clear(Color.Transparent);
			g.Dispose();
		}
		
		public void getRoads(List<List<Vertex>> roads, List<float> pesos) {//da error
			Prey.to_roads(roads, pesos);
				foreach(Prey sprite in preys) {
				if(sprite.changeToRoad()) {
					//cambiar ruta
					sprite.returnRoad();
				}
			}
		}
		
		public void preyMove() {
			foreach(Prey prey in preys) {
				if(prey.dead) {
					 continue;
				}
				//come cereza y se hace invisible
				collisionCherry(prey);
				
				if(prey.invisible && prey.containPredator()){
					//se hace inmortal por un momento
					prey.predator.newPrey(null);
					prey.newPredator(null);
				}
					
				//si se encuentra a un depredador debe huir
				if(prey.containPredator()) {
					//contiene un depredador en acecho
					//intentara huir
					prey.runAway();
					prey.survivor_speed = 1;
				}
				
				if(Prey.Speed >= prey.Path.Count) {
					prey.addRoad();
				}
			}
		}
		
		private void collisionCherry(Prey prey) {
			foreach(Entity cherry in cherrys) {
				if(prey.collision(cherry, 40) && prey.inEdge(cherry)) {
					//comio la cereza
					prey.invisible = true;
					prey.survivor_speed = 4;
					dead_cherry = cherry;
					break;
				}
			}
			cherrys.Remove(dead_cherry);
		}
		
		public void predatorMove() {
			foreach(Predator  predator in predators) {
				upDatePrey(predator);//actualiza estado derpedador - presa
				
				if(Predator.Speed >= predator.Path.Count) {
					//ya no hay ruta por recorrer y se debe agregar una nueva
					if(predator.containPrey()) {
						//contiene una presa y debe intentar seguirla
						predator.followPrey();
					} else {
						//no contiene prese y debe moverse de forma random
						predator.addRoadRandom();
					}
				}
				
				
				if(predator.containPrey() && predator.collision(predator.Prey, 45) && (predator.inEdge(predator.Prey) || predator.Path.Count < 2*Predator.Speed)) {
					//la presa esta en el rango de debora
					//comer presa
					predator.Prey.addRoadDead(exitTheScreen(predator.Prey.Path[Prey.Position]));
					//aumenta su euforia
					predator.Euforia++;
					predator.Size+=5;
					//suelta presa para poder perseguir a otra
				   	predator.Prey.newPredator(null);
					predator.newPrey(null);
				}
				
			}
				
		}
		
		private void upDatePrey(Predator predator) {
			foreach(Prey p_ in preys) {
				if(!p_.invisible && !p_.dead) {
					//si no es invisible y no a muerto la presa
					if(predator.collision(p_, 180) && !predator.containPrey() && !p_.containPredator()) {
						p_.newPredator(predator);
						predator.newPrey(p_);
						break;
					} else if(p_.containPredator() && predator.Prey == p_ && !predator.collision(p_, 180) ) {
						/*si no colisiona con la presa actual se la quitamos*/
						p_.newPredator(null);
						predator.newPrey(null);
					} else if(predator.containPrey() && predator.distance(p_) < predator.distance(predator.Prey) && !p_.containPredator()) {
						/*depredador contiene una presa, pero quiere cambiarla por otra mas cercana*/
						predator.Prey.newPredator(null);//libera presa actual
						predator.newPrey(p_);//actualizo presa
						p_.newPredator(predator);//actualizo predador de presa
					} else if(!predator.containPrey() && p_.containPredator() && predator.distance(p_) < p_.predator.distance(p_)) {
						p_.predator.newPrey(null);
						predator.newPrey(p_);
						p_.newPredator(predator);
					} else if(predator.containPrey() && predator.Prey != p_ && p_.containPredator() && predator.distance(p_) < predator.distance(predator.Prey) &&  predator.distance(p_) < p_.predator.distance(p_)) {
						/*depredador contiene presa, pero encuentra una presa mas cercana que ya contiene su depredador*/
						p_.predator.newPrey(null);//depredador ajeno deja de seguir a su presa
						predator.Prey.newPredator(null);//depredador deja de seguir a su presa
						predator.newPrey(p_);//predador cambia a nueva presa
						p_.newPredator(predator);//nueva presa es perseguida
					}
				}
			}
				
		}
		
		private List<Point> exitTheScreen(Point p1) {
			//funcion DDA para generar los puntos desde la presa muerta hasta (1, 30)
			int x1 = p1.X,	y1 = p1.Y,
				x2 = 1,		y2 = 30;
			
			float ax, ay, x, y, res, i = 0;
			
			if(Math.Abs(x2 - x1) >= Math.Abs(y2 - y1)) {
				res = Math.Abs(x2 - x1);
			} else {
				res = Math.Abs(y2 - y1);
			}
			
			ax = (x2 - x1) / res;
			ay = (y2 - y1) / res;
			x = (float)x1;
			y = (float)y1;
			List<Point> points = new List<Point>();
			
			int fliker = 0;
			
			while(i <= res) {
				if((fliker++ % 2) == 0) {
					points.Add(new Point((int)x, (int)y));
				}
				x += ax;
				y += ay;
				i++;
			}
			return points;
		}
		
		public bool gameOver() {
			return preys.Count <= Prey.Deads || (goal = win()) != null;
		}
		
		private Prey win() {
			foreach(Prey p in preys) {
				if(p.goal) {
					if(p.containPredator()) { p.predator.newPrey(null); p.newPredator(null); }
					return p;
				}
			}
			return null;
		}
		
		public void clear() {
			preys.RemoveAll(p => p.dead);//remueve las presas muertas
			preys.Remove(goal);//remueve la presa que llego al destino
			preys.ForEach(p => p.PosInit = -1);
			predators.ForEach(p => p.PosInit = -1);
			Prey.Deads = 0;//ya no hay presas muertas
			destiny = null;//elimina el destino
			Start = false;//la animacion ya no esta activa
		}
		
	}
}
