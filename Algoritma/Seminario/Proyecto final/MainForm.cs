/*
 * Creado por SharpDevelop.
 * Usuario: david
 * Fecha: 03/03/2020
 * Hora: 08:00 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
using System;
using System.Timers;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace ProyectPreyPredator {
	public partial class MainForm : Form {
		public MainForm() {
			InitializeComponent();
			resize();
			openFileImage.FileName = "images\\ent 1.png";
			loadMap();
		}
		
		void clear() {
			graph.Clear();
			graph.Vertexs.Clear();
			MenuItemDestiny.Checked = false;			
		}
		
		void loadMap() {
			clear();
			//funcion para limpiar el analisis anterior...
			tabControl.SelectedIndex = 0;
			bmpBackGround = new Bitmap(openFileImage.FileName);
			bmpForeGround = new Bitmap(bmpBackGround.Width, bmpBackGround.Height);
			pictureBoxImage.BackgroundImage = bmpBackGround;
			pictureBoxImage.BackgroundImageLayout = ImageLayout.Zoom;
			
			pictureBoxMap.Image = bmpForeGround;
			
			pictureBoxImage.Image = bmpSave;
			
			//analiso la imagen en busca de circulos
			analizeMap();
			//genera las lineans con DDA
			generateAndDrawEdges();
			//insertar etiquetas
			
			drawLbl();
			pictureBoxMap.BackgroundImage = bmpBackGround;
			pictureBoxMap.BackgroundImageLayout = ImageLayout.Zoom;
			tabControl.SelectedIndex = 1;
			
			Graphics g = Graphics.FromImage(bmpForeGround);
			g.Clear(Color.Transparent);
			pictureBoxMap.Image = bmpForeGround;
			g.Dispose();
			
			engine = new Engine(bmpForeGround);
			//cargo el grafo para todas las entidades
			Entity.graph = graph;
			//cargar las aristas a cada presa
			Prey.Edges =  graph.getEdges();
		}
		
		void analizeMap() {
			
	        for (int y = 0; y < bmpBackGround.Height; y++) {
	            for (int x = 0; x < bmpBackGround.Width; x++) {
					if(bmpBackGround.GetPixel(x,y).ToArgb().Equals(Color.Black.ToArgb())) {
						//
						if(pixelInArea( new Figure(x, y, 1)) == null) {
							circle.searchCenter(x, y, bmpBackGround);
							if(circle.isCircle(bmpBackGround)) {
								graph.addVertex(new Figure(circle));
							}
						}
					}
				}
			}
			
		}
		
		void drawLbl() {
			int size = graph.Vertexs[0].Circle.R+3;
			Graphics grap = Graphics.FromImage(bmpBackGround);
			if (grap == null)
				return;
			Font font = new Font("Arial", size);
			SolidBrush brocha = new SolidBrush(Color.White);
			
			for(int i = 0; i < graph.Vertexs.Count; i++) {
				if(i < 10)
					grap.DrawString(i.ToString(), font, brocha, graph.Vertexs[i].Circle.X-(size/3+size/4), graph.Vertexs[i].Circle.Y-(size/2+size/5));
				else
					grap.DrawString(i.ToString(), font, brocha, graph.Vertexs[i].Circle.X-(size/2+10), graph.Vertexs[i].Circle.Y-(size/2+4));
			}
			grap.Dispose();
		}
		
		void generateAndDrawEdges() {
			Graphics g = Graphics.FromImage(bmpBackGround);
			Pen pen = new Pen(Color.Blue, 2);
			Point[] points = new Point[2];
			
			Matriz = new int[graph.Vertexs.Count, graph.Vertexs.Count];
			List<Point> path = new List<Point>();
			//genero copia de la imagen para hacer el analisis
			Bitmap bmp = new Bitmap(openFileImage.FileName);
			
			float weight = 0;//peso -> ponderacion
			
			for(int i = 0; i < graph.Vertexs.Count; i++) {
				for(int j = i+1; j < graph.Vertexs.Count; j++) {
					//obtengo la distancia entre el centro de los circulos
					weight = graph.Vertexs[i].Circle.distance(graph.Vertexs[j].Circle);
					
					path = collisionDDA(graph.Vertexs[i].Circle, graph.Vertexs[j].Circle, bmp);
					
					if(path != null) {
						//si no encuentra una colision...
						//genero la arista
						graph.addEdge(i, j, weight, path);
						//invierto la lista para generar el camino inverso
						path.Reverse();
						graph.addEdge(j, i, weight, path);
						Matriz[i,j] = 1;
						Matriz[j,i] = 1;
						
						//dibujo las aristas
						points = lineExtern(graph.Vertexs[i].Circle, graph.Vertexs[j].Circle);
						g.DrawLine(pen, points[0].X, points[0].Y, points[1].X, points[1].Y);
					}
				}
			}
			path.Clear();
			bmp.Dispose();
			g.Dispose();
		}
		
		Point[] lineExtern(Figure f1, Figure f2) {
			Point[] points = new Point[2];
			//calcular puntos de salida
			int distance = (int)f1.distance(f2),//distancia entre ambos ciruclos
				X = Math.Abs(f1.X - f2.X),		//cateto ancho
				Y = Math.Abs(f1.Y - f2.Y),		//cateto alto
				X1,								//x1 resultante
				Y1,								//y1 resultante
				X2,								//x2 resultante
				Y2;								//y2 resultante
				
			if(f1.Y < f2.Y) {
				//f1 esta arriba de f2 --> Valor Y
				//f1 suma
				//f2 resta
				Y1 = f1.Y + (Y*f1.R/distance);
				Y2 = f2.Y - (Y*f2.R/distance);
			} else {
				//f1 esta debajo de f2 --> Valor Y
				//f1 resta
				//f2 suma
				Y1 = f1.Y - (Y*f1.R/distance);
				Y2 = f2.Y + (Y*f2.R/distance);
			}
			
			if(f1.X < f2.X) {
				//f1 esta izq de f2 --> Valor X
				//f1 suma
				//f2 resta
				X1 = f1.X + (X*f1.R/distance);
				X2 = f2.X - (X*f2.R/distance);
			} else {
				//f1 esta der de f2 --> Valor X
				//f1 resta
				//f2 suma
				X1 = f1.X - (X*f1.R/distance);
				X2 = f2.X + (X*f2.R/distance);
			}
			points[0].X = X1;
			points[0].Y = Y1;
			points[1].X = X2;
			points[1].Y = Y2;
			
			return points;
		}
		
		List<Point> collisionDDA(Figure c1, Figure c2, Bitmap bmp) {
			float r1 = c1.R + 5, r2 = c2.R + 5;
			int x1 = c1.X, y1 = c1.Y, x2 = c2.X, y2 = c2.Y;
			
			float ax, ay, x, y, res, i = 0, distanceLineActual;
			
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
			
			while(i <= res) {
				distanceLineActual = c1.distance((int)x, (int)y);
				if(distanceLineActual > r1 && distanceLineActual < c1.distance(c2)-r2) {
					//este condicional impide el analizis dentro del area de los circulos
					//esto evitara notar colisiones con el mismo circulo
					if(collision((int)x, (int)y, bmp))
						return null;
					if(collision((int)(x + ax), (int)y, bmp))
						return null;
				}
				points.Add(new Point((int)x, (int)y));
				x += ax;
				y += ay;
				i++;
			}
			return points;
		}
		
		bool collision(int x, int y, Bitmap bmp) {
			//busca colision
			//si no es blanco, es una collision
			if(bmp.GetPixel(x, y).ToArgb().Equals(Color.White.ToArgb()))
				return false;
			return true;
		}
		
		Vertex pixelInArea(Figure c1) {
			//calcula coliciones entre 2 circulos o un circulo y un pixel
			foreach(Vertex v in graph.Vertexs) {
				if(v.Circle.collision(c1)) { return v; }
			}
			return null;
		}
		
		void TimerTick(object sender, EventArgs e) {
			if(!engine.gameOver()) {
				//dibuja
				engine.drawing();
				//mueve presa
				engine.preyMove();
				//mueve predador
				engine.predatorMove();
				
				//cambiar posiciones actual
				engine.ActualizePosition();
			} else {
				//apagar timer
				MenuItemAnimar.Checked = false;
				timer.Enabled = false;//apagar timer
				MenuItemDestiny.Checked = false;
				engine.clear();
				//dibuja
				engine.drawing();
			}
			pictureBoxMap.Refresh();
		}
		
		void PictureBoxMouseClick(object sender, MouseEventArgs e) {
			//la animacion ya incio y no puede agregarse presa, depredador o cambiar destino
			if(engine.Start) { return; }
			
			Point p = ajustarZoom(e);
			Vertex v = new Vertex();
			Figure c = new Figure();
			
			if((v = pixelInArea( new Figure(p.X, p.Y))) != null) {
				c = v.Circle;
				
				if(MenuItemDestiny.Checked) {
					if(e.Button == MouseButtons.Left) {
						//cargo el grafo a dijstra
						dijstra = new Dijstra(graph, Matriz);
						//selccionar origen
						dijstra.origen(v);
						engine.Destiny = c;//obtengo el destino
						
						engine.drawing();
						pictureBoxMap.Refresh();
						return;
					}
				}
				
				//impide que se seleccione un vertice que ya tenga una presa o predador
				foreach(Prey prey in engine.Preys) {
					if(prey.PosInit == v.Id) {
						MessageBox.Show("Vertice ya ocupado");
						return;
					}
				}
				
				foreach(Predator predator in engine.Predators) {
					if(predator.PosInit == v.Id) {
						MessageBox.Show("Vertice ya ocupado");
						return;
					}
				}
				
				if(e.Button == MouseButtons.Left) {
					engine.Preys.Add(new Prey(v.Id, 65, new Point(c.X, c.Y)));
				}
				
				if(e.Button == MouseButtons.Right) {
					engine.Predators.Add(new Predator(v.Id, 65, new Point(c.X, c.Y)));
				}
				engine.drawing();
				pictureBoxMap.Refresh();
			}
		}
		
		void PictureBoxMouseMove(object sender, MouseEventArgs e) {
			Point p = ajustarZoom(e);
			if(pixelInArea( new Figure(p.X, p.Y)) != null) {
				pictureBoxMap.Cursor = Cursors.Hand;	
			} else  {
				pictureBoxMap.Cursor = Cursors.Default;
			}
		}
		
		
		void MenuSpeed(object sender, EventArgs e) {
			Selection selection = new Selection();
			selection.ShowDialog();
			selection.Dispose();
		}
		
		void MenuShowStatus(object sender, EventArgs e) {
			Status status = new Status(engine.Preys, engine.Predators);
			status.ShowDialog();
			status.Dispose();
		}
		
		void MenuAnimate(object sender, EventArgs e) {
			if(MenuItemAnimar.Checked && engine.Destiny != null) {
				if(!engine.Start) {
					//crear caminos dijstra
					dijstra.roads();
					//si aun no incia el juego, entonces iniciarlo
					List<List<Vertex>> roads = new List<List<Vertex>>();
					List<float> pesos = new List<float>();
					foreach(Vertex v2 in graph.Vertexs) {
						roads.Add(dijstra.draw(v2));
						pesos.Add(dijstra.distancia);
						//MessageBox.Show("distancia: "+dijstra.distancia + " vertice: " + v.Id);
					}
					engine.getRoads(roads, pesos);
				}
				
				timer.Enabled = true;
				engine.Start = true;
			} else {
				MenuItemAnimar.Checked = false;
				timer.Enabled = false;
			}
		}
		
		void MenuDeleteEntity(object sender, EventArgs e) {
			Remove remove_ = new Remove(engine.Preys, engine.Predators);
			remove_.ShowDialog();
			remove_.Dispose();
			engine.drawing();
			pictureBoxMap.Refresh();
		}
		
		void MenuCreateDestiny(object sender, EventArgs e) {
			if(engine.Preys.Count == 0) {
				MenuItemDestiny.Checked = false;
				MessageBox.Show("Debe haber por lo menos una presa");
				return;
			}
		}
	
		void MenuSaveImage(object sender, EventArgs e) {
			if(openFileImage.FileName == "file") { 
				MessageBox.Show("No se puede guardar la imagen");
				return;
			}
			
			if(saveFileDialog.ShowDialog() == DialogResult.OK) {
				//cargo el fondo
				bmpSave = new Bitmap(bmpBackGround);
				
				pictureBoxImage.Image = bmpSave;
				engine.CanvasSave = bmpSave;
				engine.drawing(false);
				
				pictureBoxImage.Refresh();
			
				pictureBoxImage.Image.Save(saveFileDialog.FileName + ".PNG");
				
				engine.removeSave();
				pictureBoxImage.Refresh();
				
				MessageBox.Show("La imagen se ha guardado con exito");
			}
			
		}
		
		void MenuImportMap(object sender, EventArgs e) {
			if(openFileImage.ShowDialog() == DialogResult.OK) {
				loadMap();
			}
		}
		
		void MenuCherrys(object sender, EventArgs e) {
			//crear cerezas
			engine.Cherrys.Clear();
			//engine.Cherrys.RemoveRange(0, engine.Cherrys.Count);
			if(cerezasToolStripMenuItem.Checked) {
				Random random = new Random();
				int pos, par = 0;
				foreach(Edge ee in graph.getEdges()) {
					if(random.Next(0, 4) == 0 && par%2==0) {
						pos = random.Next(0, ee.Path.Count);
						engine.Cherrys.Add(new Entity(ee.Path[pos], ee.Origen.Id, ee.Destino.Id, 66));
					}
					par++;
				}
			}
			engine.drawing();
			pictureBoxMap.Refresh();
		}
		
		
		
		void MenuItemHelp(object sender, EventArgs e) {
			Help help = new Help();
			help.ShowDialog();
			help.Dispose();
		}
	}
}
