/*
 * Creado por SharpDevelop.
 * Usuario: dagur
 * Fecha: 04/03/2020
 * Hora: 11:55 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
 using System;
 using System.Drawing;
 using System.Windows.Forms;
 
 
namespace ProyectPreyPredator {
	partial class Help {
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent() {
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Help));
			this.lblClosed = new System.Windows.Forms.Label();
			this.tabControl = new System.Windows.Forms.TabControl();
			this.tabPrey = new System.Windows.Forms.TabPage();
			this.label3 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.tabPredator = new System.Windows.Forms.TabPage();
			this.label2 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.tabCherry = new System.Windows.Forms.TabPage();
			this.label6 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.tabFile = new System.Windows.Forms.TabPage();
			this.label8 = new System.Windows.Forms.Label();
			this.label7 = new System.Windows.Forms.Label();
			this.tabOptions = new System.Windows.Forms.TabPage();
			this.label14 = new System.Windows.Forms.Label();
			this.label13 = new System.Windows.Forms.Label();
			this.label12 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.label10 = new System.Windows.Forms.Label();
			this.label9 = new System.Windows.Forms.Label();
			this.preyDescripcion = new System.Windows.Forms.Label();
			this.PredatorDEscripcion = new System.Windows.Forms.Label();
			this.cherryDescripcion = new System.Windows.Forms.Label();
			this.fileDescripcion = new System.Windows.Forms.Label();
			this.optionDescription = new System.Windows.Forms.Label();
			this.tabControl.SuspendLayout();
			this.tabPrey.SuspendLayout();
			this.tabPredator.SuspendLayout();
			this.tabCherry.SuspendLayout();
			this.tabFile.SuspendLayout();
			this.tabOptions.SuspendLayout();
			this.SuspendLayout();
			// 
			// lblClosed
			// 
			this.lblClosed.BackColor = System.Drawing.Color.Transparent;
			this.lblClosed.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblClosed.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblClosed.ForeColor = System.Drawing.Color.Red;
			this.lblClosed.Location = new System.Drawing.Point(494, -5);
			this.lblClosed.Name = "lblClosed";
			this.lblClosed.Size = new System.Drawing.Size(25, 35);
			this.lblClosed.TabIndex = 4;
			this.lblClosed.Text = "x";
			this.lblClosed.Click += new System.EventHandler(this.LblClosedClick);
			// 
			// tabControl
			// 
			this.tabControl.Controls.Add(this.tabPrey);
			this.tabControl.Controls.Add(this.tabPredator);
			this.tabControl.Controls.Add(this.tabCherry);
			this.tabControl.Controls.Add(this.tabFile);
			this.tabControl.Controls.Add(this.tabOptions);
			this.tabControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tabControl.ImeMode = System.Windows.Forms.ImeMode.Off;
			this.tabControl.ItemSize = new System.Drawing.Size(1, 1);
			this.tabControl.Location = new System.Drawing.Point(12, 80);
			this.tabControl.Multiline = true;
			this.tabControl.Name = "tabControl";
			this.tabControl.SelectedIndex = 0;
			this.tabControl.Size = new System.Drawing.Size(500, 383);
			this.tabControl.TabIndex = 5;
			// 
			// tabPrey
			// 
			this.tabPrey.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.tabPrey.Controls.Add(this.label3);
			this.tabPrey.Controls.Add(this.label1);
			this.tabPrey.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.tabPrey.Location = new System.Drawing.Point(4, 14);
			this.tabPrey.Name = "tabPrey";
			this.tabPrey.Padding = new System.Windows.Forms.Padding(3);
			this.tabPrey.Size = new System.Drawing.Size(492, 365);
			this.tabPrey.TabIndex = 0;
			// 
			// label3
			// 
			this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label3.Location = new System.Drawing.Point(6, 180);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(480, 89);
			this.label3.TabIndex = 2;
			this.label3.Text = "Sprite: Fantasmas de pacman, contien 6 colores distintos, rojo, verde, cafe claro" +
			", rosa, gris, morado y azul fuerte, este ultimo aparece cuando la estan acechand" +
			"o.";
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label1.Location = new System.Drawing.Point(6, 3);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(480, 177);
			this.label1.TabIndex = 0;
			this.label1.Text = resources.GetString("label1.Text");
			// 
			// tabPredator
			// 
			this.tabPredator.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.tabPredator.Controls.Add(this.label2);
			this.tabPredator.Controls.Add(this.label4);
			this.tabPredator.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.tabPredator.Location = new System.Drawing.Point(4, 14);
			this.tabPredator.Name = "tabPredator";
			this.tabPredator.Padding = new System.Windows.Forms.Padding(3);
			this.tabPredator.Size = new System.Drawing.Size(492, 365);
			this.tabPredator.TabIndex = 1;
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label2.Location = new System.Drawing.Point(6, 168);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(480, 53);
			this.label2.TabIndex = 2;
			this.label2.Text = "Sprite: pacman de color amarillo y azul claro, este ultimo aparece cuando esta en" +
			" acecho.";
			// 
			// label4
			// 
			this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label4.Location = new System.Drawing.Point(6, 3);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(480, 165);
			this.label4.TabIndex = 1;
			this.label4.Text = resources.GetString("label4.Text");
			// 
			// tabCherry
			// 
			this.tabCherry.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.tabCherry.Controls.Add(this.label6);
			this.tabCherry.Controls.Add(this.label5);
			this.tabCherry.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.tabCherry.Location = new System.Drawing.Point(4, 14);
			this.tabCherry.Name = "tabCherry";
			this.tabCherry.Padding = new System.Windows.Forms.Padding(3);
			this.tabCherry.Size = new System.Drawing.Size(492, 365);
			this.tabCherry.TabIndex = 2;
			// 
			// label6
			// 
			this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label6.Location = new System.Drawing.Point(6, 3);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(480, 84);
			this.label6.TabIndex = 4;
			this.label6.Text = "Cerezas: cuando una PRESA debora una, esta se hace invisible para los DEPREDADORE" +
			"S y aumenta su velocidad en 3 unidades, esto le afecta mientras no llegue al pro" +
			"ximo vertice.";
			// 
			// label5
			// 
			this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold);
			this.label5.Location = new System.Drawing.Point(9, 87);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(480, 43);
			this.label5.TabIndex = 3;
			this.label5.Text = "Sprite:un par de cerezas rojas.";
			// 
			// tabFile
			// 
			this.tabFile.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.tabFile.Controls.Add(this.label8);
			this.tabFile.Controls.Add(this.label7);
			this.tabFile.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.tabFile.Location = new System.Drawing.Point(4, 14);
			this.tabFile.Name = "tabFile";
			this.tabFile.Padding = new System.Windows.Forms.Padding(3);
			this.tabFile.Size = new System.Drawing.Size(492, 365);
			this.tabFile.TabIndex = 3;
			// 
			// label8
			// 
			this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label8.Location = new System.Drawing.Point(6, 58);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(480, 74);
			this.label8.TabIndex = 5;
			this.label8.Text = "Exportar Imagen: Genera una imagen con el mapa y todas las entidades que se encue" +
			"ntren en el y permite guardarla.";
			// 
			// label7
			// 
			this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label7.Location = new System.Drawing.Point(6, 3);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(480, 53);
			this.label7.TabIndex = 4;
			this.label7.Text = "Importar Mapa: Permite seleccionar una imagen para generar un mapa.";
			// 
			// tabOptions
			// 
			this.tabOptions.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.tabOptions.Controls.Add(this.label14);
			this.tabOptions.Controls.Add(this.label13);
			this.tabOptions.Controls.Add(this.label12);
			this.tabOptions.Controls.Add(this.label11);
			this.tabOptions.Controls.Add(this.label10);
			this.tabOptions.Controls.Add(this.label9);
			this.tabOptions.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.tabOptions.Location = new System.Drawing.Point(4, 14);
			this.tabOptions.Name = "tabOptions";
			this.tabOptions.Padding = new System.Windows.Forms.Padding(3);
			this.tabOptions.Size = new System.Drawing.Size(492, 365);
			this.tabOptions.TabIndex = 4;
			// 
			// label14
			// 
			this.label14.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label14.Location = new System.Drawing.Point(6, 270);
			this.label14.Name = "label14";
			this.label14.Size = new System.Drawing.Size(480, 44);
			this.label14.TabIndex = 15;
			this.label14.Text = "Velocidad: Permite Cambiar la velociada de las PRESAS y/o DEPREDADORES";
			// 
			// label13
			// 
			this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label13.Location = new System.Drawing.Point(6, 3);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(480, 62);
			this.label13.TabIndex = 14;
			this.label13.Text = "Animar: activa/desactiva la animacion en el mapa. Esta opcion solo se puede activ" +
			"ar si hay un destino seleccionado";
			// 
			// label12
			// 
			this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label12.Location = new System.Drawing.Point(3, 314);
			this.label12.Name = "label12";
			this.label12.Size = new System.Drawing.Size(480, 46);
			this.label12.TabIndex = 13;
			this.label12.Text = "Ver Estados: Muestra la informacion de todas las PRESAS y DEPREDADORES";
			// 
			// label11
			// 
			this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label11.Location = new System.Drawing.Point(6, 220);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(480, 50);
			this.label11.TabIndex = 12;
			this.label11.Text = "Eliminar: Permite eliminar una presa o un depredador que se encuentren en el mapa" +
			"";
			// 
			// label10
			// 
			this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label10.Location = new System.Drawing.Point(6, 169);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(480, 54);
			this.label10.TabIndex = 11;
			this.label10.Text = "Cerezas: activa/descativa las cerezas en el mapa, estas siempre se generaran de f" +
			"orma aleatoria";
			// 
			// label9
			// 
			this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label9.Location = new System.Drawing.Point(6, 70);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(480, 99);
			this.label9.TabIndex = 10;
			this.label9.Text = resources.GetString("label9.Text");
			// 
			// preyDescripcion
			// 
			this.preyDescripcion.Cursor = System.Windows.Forms.Cursors.Hand;
			this.preyDescripcion.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.preyDescripcion.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.preyDescripcion.Location = new System.Drawing.Point(12, 21);
			this.preyDescripcion.Name = "preyDescripcion";
			this.preyDescripcion.RightToLeft = System.Windows.Forms.RightToLeft.No;
			this.preyDescripcion.Size = new System.Drawing.Size(93, 23);
			this.preyDescripcion.TabIndex = 6;
			this.preyDescripcion.Text = "PRESA";
			this.preyDescripcion.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
			this.preyDescripcion.Click += new System.EventHandler(this.PreyDescripcionClick);
			// 
			// PredatorDEscripcion
			// 
			this.PredatorDEscripcion.Cursor = System.Windows.Forms.Cursors.Hand;
			this.PredatorDEscripcion.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.PredatorDEscripcion.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.PredatorDEscripcion.Location = new System.Drawing.Point(111, 21);
			this.PredatorDEscripcion.Name = "PredatorDEscripcion";
			this.PredatorDEscripcion.Size = new System.Drawing.Size(166, 23);
			this.PredatorDEscripcion.TabIndex = 7;
			this.PredatorDEscripcion.Text = "DEPREDADOR";
			this.PredatorDEscripcion.Click += new System.EventHandler(this.PredatorDEscripcionClick);
			// 
			// cherryDescripcion
			// 
			this.cherryDescripcion.Cursor = System.Windows.Forms.Cursors.Hand;
			this.cherryDescripcion.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.cherryDescripcion.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.cherryDescripcion.Location = new System.Drawing.Point(283, 21);
			this.cherryDescripcion.Name = "cherryDescripcion";
			this.cherryDescripcion.Size = new System.Drawing.Size(106, 23);
			this.cherryDescripcion.TabIndex = 8;
			this.cherryDescripcion.Text = "CEREZA";
			this.cherryDescripcion.Click += new System.EventHandler(this.CherryDescripcionClick);
			// 
			// fileDescripcion
			// 
			this.fileDescripcion.Cursor = System.Windows.Forms.Cursors.Hand;
			this.fileDescripcion.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.fileDescripcion.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.fileDescripcion.Location = new System.Drawing.Point(12, 49);
			this.fileDescripcion.Name = "fileDescripcion";
			this.fileDescripcion.Size = new System.Drawing.Size(117, 23);
			this.fileDescripcion.TabIndex = 9;
			this.fileDescripcion.Text = "ARCHIVO";
			this.fileDescripcion.Click += new System.EventHandler(this.FileDescripcionClick);
			// 
			// optionDescription
			// 
			this.optionDescription.Cursor = System.Windows.Forms.Cursors.Hand;
			this.optionDescription.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.optionDescription.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.optionDescription.Location = new System.Drawing.Point(135, 49);
			this.optionDescription.Name = "optionDescription";
			this.optionDescription.Size = new System.Drawing.Size(142, 23);
			this.optionDescription.TabIndex = 10;
			this.optionDescription.Text = "OPCIONES";
			this.optionDescription.Click += new System.EventHandler(this.OptionDescriptionClick);
			// 
			// Help
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.ClientSize = new System.Drawing.Size(524, 476);
			this.Controls.Add(this.optionDescription);
			this.Controls.Add(this.fileDescripcion);
			this.Controls.Add(this.cherryDescripcion);
			this.Controls.Add(this.PredatorDEscripcion);
			this.Controls.Add(this.preyDescripcion);
			this.Controls.Add(this.tabControl);
			this.Controls.Add(this.lblClosed);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "Help";
			this.Text = "overlayTree";
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseUp);
			this.tabControl.ResumeLayout(false);
			this.tabPrey.ResumeLayout(false);
			this.tabPredator.ResumeLayout(false);
			this.tabCherry.ResumeLayout(false);
			this.tabFile.ResumeLayout(false);
			this.tabOptions.ResumeLayout(false);
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Label label14;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.Label label12;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TabPage tabOptions;
		private System.Windows.Forms.TabPage tabFile;
		private System.Windows.Forms.TabPage tabCherry;
		private System.Windows.Forms.Label optionDescription;
		private System.Windows.Forms.Label fileDescripcion;
		private System.Windows.Forms.Label cherryDescripcion;
		private System.Windows.Forms.Label PredatorDEscripcion;
		private System.Windows.Forms.Label preyDescripcion;
		private System.Windows.Forms.TabPage tabPredator;
		private System.Windows.Forms.TabPage tabPrey;
		private System.Windows.Forms.TabControl tabControl;
		private System.Windows.Forms.Label lblClosed;
		int mov, movX, movY;
		
		void LblClosedClick(object sender, EventArgs e) { this.Close(); }
		
		void OverlayTreeMouseDown(object sender, MouseEventArgs e) {
			mov = 1;
			movX = e.X;
			movY = e.Y;
		}
		
		void OverlayTreeMouseMove(object sender, MouseEventArgs e) {
			if(mov == 1)
				this.SetDesktopLocation(MousePosition.X-movX, MousePosition.Y-movY);
		}
		
		void OverlayTreeMouseUp(object sender, MouseEventArgs e) {
			mov = 0;
		}
		
	}
}
