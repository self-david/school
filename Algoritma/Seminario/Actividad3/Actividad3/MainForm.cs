﻿/*
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
using System.Drawing.Drawing2D;
using System.Windows.Forms;
using System.Threading;

namespace Actividad3 {
	delegate void Lambda();
	public partial class MainForm : Form {
		int mov, movX, movY;
		bool animation = false;
		List<Particle> particles;
		Brush bc = new SolidBrush(Color.Red);
		String timeK = "", timeP = "";
		public MainForm() {
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			resize();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void clear() {
			graph.Clear();
			graph.vertex().Clear();
			listBoxVertex.Items.Clear();
			treeSelect = false;
			idVertexSelect = -1;
			lblKrukal.Text = "K. Vertice " + " Destinos " + timeK;
			lblPrim.Text = "P. Vertice " + " Destinos " + timeP;
			lblKrukal.ForeColor = Color.WhiteSmoke;
			lblPrim.ForeColor = Color.WhiteSmoke;
		}
		
		void LblLoadImgClick(object sender, EventArgs e) {
			if(openFileImage.ShowDialog() == DialogResult.OK) {
				clear();
				//funcion para limpiar el analisis anterior...
				tabControl.SelectedIndex = 0;
				bmp = new Bitmap(openFileImage.FileName);
				bmpBackGround = new Bitmap(openFileImage.FileName);
				pictureBoxInit.Image = bmp;
				
				pictureBoxSecond.Image = bmp;
				
				pictureBoxKruskal.Image = bmpBackGround;
				pictureBoxPrim.Image = bmpBackGround;
				
				//analiso la imagen en busca de circulos
				analizeImg();
				//genera las lineans con DDA
				generateEdges();
				//insertar etiquetas
				drawLbl();
				//dibujo los caminos
				drawEdges(graph);
				pictureBoxSecond.BackgroundImage = bmpBackGround;
				pictureBoxSecond.BackgroundImageLayout = ImageLayout.Zoom;
				tabControl.SelectedIndex = 1;
				//limpio bitmap para usarlo como lienzo en blanco
				bmp = new Bitmap(bmp);
				Graphics g = Graphics.FromImage(bmp);
				g.Clear(Color.Transparent);
				pictureBoxSecond.Image = bmp;
				bmpBackGround2 = new Bitmap(bmpBackGround);
			}
		}
		
		void analizeImg() {
			int id = 0;
	        for (int y = 0; y < bmp.Height; y++) {
	            for (int x = 0; x < bmp.Width; x++) {
					if(bmp.GetPixel(x,y).ToArgb().Equals(Color.Black.ToArgb())) {
						//
						if(pixelInArea( new Figure(x, y, 1)) == null) {
							circle.searchCenter(x, y, bmp);
							if(circle.isCircle(bmp)) {
								graph.addVertex(new Figure(circle),  id);
								listBoxVertex.Items.Add(
									graph.vertex()[graph.vertex().Count-1].ToString());
								id++;
							}
						}
					}
				}
			}
			
		}
		
		void LblGenerateTreeClick(object sender, EventArgs e) {
			if(openFileImage.FileName == "file") {
				MessageBox.Show("Debe seleccionar una imagen primero");
				return;
			}
			if(idVertexSelect == -1) {
				MessageBox.Show("Debe seleccionar un vertice primero");
				return;
			}
			//escojer con que algoritmo dibujar...
			SelecTree ST = new SelecTree();
			ST.ShowDialog();
			
			if(ST.select == -1) {
				return;
			}
			//contador de tiempo init
			DateTime dt = new DateTime();
			dt = DateTime.Now;
			//genero arbol con kruskal
			kruskal = new Kruskal(graph);
			kruskal.generate();
			TimeSpan transcurrio = DateTime.Now - dt;
			//contador de tiempo finish
			timeK = transcurrio.TotalMilliseconds.ToString();
			
			//contador de tiempo init
			DateTime dt2 = new DateTime();
			//genero arbol con prim
			prim = new Prim(graph);
			prim.generate(idVertexSelect);
			//contador de tiempo finish
			TimeSpan transcurrio2 = DateTime.Now - dt2;
			timeP = transcurrio2.Milliseconds.ToString();
			
			MessageBox.Show(timeK + " - " + timeP);
			
			Color[] c = {Color.BlueViolet, Color.Pink};
			int[] size = {14, 8}, parpadeo = {15, 10000};
			
			//cargar copia del fondo antes de dibujar
			bmpBackGround = new Bitmap(bmpBackGround2);
			pictureBoxSecond.BackgroundImage = bmpBackGround;
			
			if(ST.select == 1) {
				//Kruskal
				foreach(Edge ee in kruskal.edges) {
					DDA(ee.Origen.Circle, ee.Destino.Circle, c[0], size[0], parpadeo[0], pictureBoxSecond);
				}
				lblKrukal.ForeColor = c[0];
				//prim
				bmpBackGround = new Bitmap(bmpBackGround);
				foreach(Edge ee in prim.edges) {
					DDA(ee.Origen.Circle, ee.Destino.Circle, c[1], size[1], parpadeo[1], pictureBoxSecond);
				}
				lblPrim.ForeColor = c[1];
			} else {
				//prim
				foreach(Edge ee in prim.edges) {
					DDA(ee.Origen.Circle, ee.Destino.Circle, c[0], size[0], parpadeo[0], pictureBoxSecond);
				}
				lblPrim.ForeColor = c[0];
				bmpBackGround = new Bitmap(bmpBackGround);
				//Kruskal
				foreach(Edge ee in kruskal.edges) {
					DDA(ee.Origen.Circle, ee.Destino.Circle, c[1], size[1], parpadeo[1], pictureBoxSecond);
				}
				lblKrukal.ForeColor = c[1];
				
			}
			
			pictureBoxSecond.BackgroundImage = bmpBackGround;
			treeSelect = true;
			//timer1.Enabled = true;

		}
		
		void LblAnimateClick(object sender, EventArgs e) {
			if(idVertexSelect == -1) {
				MessageBox.Show("Debe seleccionar un vertice primero");
				return;
			}
			if(!treeSelect) {
				MessageBox.Show("debe eleccionar un arbol de\nrecubrimiento minimo primero");
				return;
			}
			int diametro = (graph.vertex()[idVertexSelect].Circle.R*2) + 10;
			int totalK = diametro * kruskal.minimumPath.vertex()[idVertexSelect].Edge.Count;
			int totalP = diametro * prim.minimumPath.vertex()[idVertexSelect].Edge.Count;
			overlayTree o = new overlayTree(totalK, totalP);
			o.ShowDialog();
			
			particles = new List<Particle>();
			
			if(o.tree == -1) {
				MessageBox.Show("tienes que seleccionar");
				return;
			}
			
			if(o.tree == 1) {
				animate(kruskal.minimumPath, o.diametroK);
			}else {
				animate(prim.minimumPath, o.diametroP);
			}
			
			
			
		}
		
		void animate(Graph gr, int diametro) {
			List<int> visitados = new List<int>();
			List<int> destinos  = new List<int>();
			List<int> aux       = new List<int>();
			destinos.Add(idVertexSelect);
			int count, d_part;
							
			Lambda AddParticles = () => {
				int id_e = 0;
				
				foreach(int id_o in destinos) {
					foreach(Edge edge in gr.vertex()[id_o].Edge) {
						count = gr.vertex()[id_o].Edge.Count;
						if(!visitados.Contains(edge.Destino.Id)) {
							
							//encontrar la particula que me llevo a este punto
							if(destinos.Count == 1 && visitados.Count == 0) {
								//primer origen
								d_part = diametro/count;
							} else {
								//encontrar diametro antecesor de la particula
								count--;
								d_part = particles.Find(x => x.destino == edge.Origen.Id).diametro/count;
								
							}
							
							//guardo las nuevas aristas
							if(edge.Destino.Circle.R*2 < d_part) {
								particles.Add(new Particle(id_o, id_e, d_part));
								particles[particles.Count-1].destino = edge.Destino.Id;
								
								//guardo los nuevos destinos
								aux.Add(edge.Destino.Id);
							}
						}
						id_e++;
					}
					id_e=0;
					visitados.Add(id_o);
				}
				destinos.Clear();
				destinos.AddRange(aux);
				aux.Clear();
			};
			
			Graphics g    = Graphics.FromImage(bmp);
			
			bool gameOver = false;
			int  anima;
			
			while(!gameOver) {
				anima = particles.Count;
				g.Clear(Color.Transparent);
				foreach(Particle p in particles) {
					Edge edge = gr.vertex()[p.origen].Edge[p.actualEdge];
					if(p.isWalking()) {
						p.walk(edge);
					} else {
						anima--;
					}
					int x = edge.setPos(p.getPos()).X;
					int y = edge.setPos(p.getPos()).Y;
					
					g.FillEllipse(bc, x-(p.diametro/2), y-(p.diametro/2), p.diametro, p.diametro);
				}
				
				pictureBoxSecond.Refresh();
				
				if(anima == 0) {
					AddParticles();
					if(destinos.Count == 0) { gameOver = true; }
				}
			}
		}
		
		void drawLbl() {
			int size = graph.vertex()[0].Circle.R+3;
			Graphics grap = Graphics.FromImage(bmpBackGround);
			if (grap == null)
				return;
			Font font = new Font("Arial", size);
			SolidBrush brocha = new SolidBrush(Color.White);
			
			for(int i = 0; i < graph.vertex().Count; i++) {
				if(i < 10)
					grap.DrawString(""+i, font, brocha, graph.vertex()[i].Circle.X-(size/3+size/4), graph.vertex()[i].Circle.Y-(size/2+size/5));
				else
					grap.DrawString(""+i, font, brocha, graph.vertex()[i].Circle.X-(size/2+10), graph.vertex()[i].Circle.Y-(size/2+4));
			}
			pictureBoxSecond.Refresh();
		}
		
		
		void generateEdges() {
			//genera las aristas entre los vertices
			float weight = 0;//peso -> ponderacion
			int id = -1;
			
			List<Point> points = new List<Point>();
			
			for(int i = 0; i < graph.vertex().Count; i++) {
				for(int j = i+1; j < graph.vertex().Count; j++) {
					//obtengo la distancia entre el centro de los circulos
					weight = graph.vertex()[i].Circle.distance(graph.vertex()[j].Circle);
					
					points = collisionDDA(graph.vertex()[i].Circle, graph.vertex()[j].Circle, bmp);
					
					if(points != null) {
						//si no encuentra una colision...
						graph.addEdge(++id, i, j, weight, points);
						List<Point> pointsR = new List<Point>(points);
						pointsR.Reverse();
						graph.addEdge(++id, j, i, weight, pointsR);
					}
				}
			}
		}
		
		void drawEdges(Graph graph) {
			//dibuja los caminos del grafo
			//Color[] c = {Color.Red, Color.Blue};
			//int k = 0;
			for(int i = 0; i<graph.vertex().Count;i++) {
				for(int j = 0; j<graph.vertex()[i].Edge.Count;j++) {
					DDA(graph.vertex()[i].Circle, graph.vertex()[i].Edge[j].Destino.Circle, Color.Red, 2, 20, pictureBoxSecond);
				}
			}
		}
		
		void DDA(Figure c1, Figure c2, Color color, int R, int parpadeo, PictureBox pb) {
			float r1 = c1.R + R/2, r2 = c2.R + R/2;
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
			
			Graphics g = Graphics.FromImage(bmpBackGround);
			Brush b = new SolidBrush(color);
			
			while(i <= res) {
				distanceLineActual = c1.distance((int)x, (int)y);
				if(distanceLineActual > r1 && distanceLineActual < c1.distance(c2)-r2) {
					//este condicional impide el analizis dentro del area de los circulos
					//g.Clear(Color.Transparent);
					g.FillEllipse(b, x-(R/2), y-(R/2), R, R);
				}
				
				x += ax;
				y += ay;
				i++;
				
				//genera una simple aimacion 
				if(i%parpadeo == 0)
				 	pb.Refresh();
			}
			pb.Refresh();	
		}
		
		List<Point> collisionDDA(Figure c1, Figure c2, Bitmap bmp_) {
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
					if(collision((int)x, (int)y, bmp_))
						return null;
					if(collision((int)(x + ax), (int)y, bmp_))
						return null;
				}
				points.Add(new Point((int)x, (int)y));
				x += ax;
				y += ay;
				i++;
			}
			return points;
		}
		
		bool collision(int x, int y, Bitmap bmp_) {
			//busca colision
			//si no es blanco, es una collision
			if(bmp_.GetPixel(x, y).ToArgb().Equals(Color.White.ToArgb()))
				return false;
			return true;
		}
		
		Vertex pixelInArea(Figure c1) {
			//calcula coliciones entre 2 circulos o un circulo y un pixel
			foreach(Vertex v in graph.vertex()) {
				if(v.Circle.collision(c1)) { return v; }
			}
			return null;
		}
		
		Point ajustarZoom(MouseEventArgs e) {
			int X, Y;
			int w_i = pictureBoxSecond.Image.Width; 
            int h_i = pictureBoxSecond.Image.Height;
            int w_c = pictureBoxSecond.Width;
            int h_c = pictureBoxSecond.Height;
             float imageRatio = w_i / (float)h_i;
            float containerRatio = w_c / (float)h_c; 

            if (imageRatio >= containerRatio) {
                float scaleFactor = w_c / (float)w_i;
                float scaledHeight = h_i * scaleFactor;
                float filler = Math.Abs(h_c - scaledHeight) / 2;  
                X = (int)(e.X / scaleFactor);
                Y = (int)((e.Y - filler) / scaleFactor);
            } else {
                float scaleFactor = h_c / (float)h_i;
                float scaledWidth = w_i * scaleFactor;
                float filler = Math.Abs(w_c - scaledWidth) / 2;
             	X = (int)((e.X - filler) / scaleFactor);
               	Y = (int)(e.Y / scaleFactor);
            }
            return new Point(X,Y);
		}		
		
		
		void PictureBoxSecondMouseClick(object sender, MouseEventArgs e) {
			Point p = ajustarZoom(e);
			Vertex v = new Vertex();
			Figure c = new Figure();
			Graphics g = Graphics.FromImage(bmp);
			
			if((v = pixelInArea( new Figure(p.X, p.Y, 1))) != null) {
				g.Clear(Color.Transparent);
				c = v.Circle;
				g.FillEllipse(bc, c.X-(c.R+4), c.Y-(c.R+4), c.R*2+8, c.R*2+8);
				
				idVertexSelect = v.Id;
				
				if(treeSelect) {
					lblKrukal.Text = "K. Vertice " + idVertexSelect + " Destinos " + kruskal.minimumPath.vertex()[idVertexSelect].Edge.Count + " - " + timeK;
					lblPrim.Text = "P. Vertice " + idVertexSelect + " Destinos " + prim.minimumPath.vertex()[idVertexSelect].Edge.Count + " - "+ timeP;
				}
					
			} else {
				g.Clear(Color.Transparent);
				idVertexSelect = -1;
					lblKrukal.Text = "K. Vertice " + " Destinos " + " - " + timeK;
					lblPrim.Text = "P. Vertice " + " Destinos " + " - " + timeP;
			}
			pictureBoxSecond.Refresh();
		}
		
		
		
		
	}
}
