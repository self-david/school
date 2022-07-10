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
	partial class Selection {
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
			this.valuePrey = new System.Windows.Forms.NumericUpDown();
			this.lblSizePrey = new System.Windows.Forms.Label();
			this.lblClosed = new System.Windows.Forms.Label();
			this.lbltype = new System.Windows.Forms.Label();
			this.lblOk = new System.Windows.Forms.Label();
			this.lblSizePredator = new System.Windows.Forms.Label();
			this.valuePredator = new System.Windows.Forms.NumericUpDown();
			this.lbl = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.valuePrey)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.valuePredator)).BeginInit();
			this.SuspendLayout();
			// 
			// valuePrey
			// 
			this.valuePrey.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(30)))), ((int)(((byte)(20)))));
			this.valuePrey.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.valuePrey.ForeColor = System.Drawing.SystemColors.Info;
			this.valuePrey.Location = new System.Drawing.Point(49, 147);
			this.valuePrey.Maximum = new decimal(new int[] {
									70,
									0,
									0,
									0});
			this.valuePrey.Minimum = new decimal(new int[] {
									1,
									0,
									0,
									0});
			this.valuePrey.Name = "valuePrey";
			this.valuePrey.Size = new System.Drawing.Size(100, 34);
			this.valuePrey.TabIndex = 0;
			this.valuePrey.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.valuePrey.Value = new decimal(new int[] {
									5,
									0,
									0,
									0});
			// 
			// lblSizePrey
			// 
			this.lblSizePrey.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
			this.lblSizePrey.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lblSizePrey.Location = new System.Drawing.Point(12, 98);
			this.lblSizePrey.Name = "lblSizePrey";
			this.lblSizePrey.Size = new System.Drawing.Size(177, 23);
			this.lblSizePrey.TabIndex = 3;
			this.lblSizePrey.Text = "Presa: ";
			this.lblSizePrey.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			// 
			// lblClosed
			// 
			this.lblClosed.BackColor = System.Drawing.Color.Transparent;
			this.lblClosed.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblClosed.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblClosed.ForeColor = System.Drawing.Color.Red;
			this.lblClosed.Location = new System.Drawing.Point(355, -3);
			this.lblClosed.Name = "lblClosed";
			this.lblClosed.Size = new System.Drawing.Size(25, 35);
			this.lblClosed.TabIndex = 4;
			this.lblClosed.Text = "x";
			this.lblClosed.Click += new System.EventHandler(this.LblClosedClick);
			// 
			// lbltype
			// 
			this.lbltype.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbltype.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lbltype.Location = new System.Drawing.Point(0, 37);
			this.lbltype.Name = "lbltype";
			this.lbltype.Size = new System.Drawing.Size(320, 23);
			this.lbltype.TabIndex = 5;
			this.lbltype.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			// 
			// lblOk
			// 
			this.lblOk.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblOk.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblOk.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lblOk.Location = new System.Drawing.Point(0, 222);
			this.lblOk.Name = "lblOk";
			this.lblOk.Size = new System.Drawing.Size(384, 35);
			this.lblOk.TabIndex = 2;
			this.lblOk.Text = "Aceptar";
			this.lblOk.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			this.lblOk.Click += new System.EventHandler(this.LblOkClick);
			this.lblOk.MouseLeave += new System.EventHandler(this.LblAceptarMouseLeave);
			this.lblOk.MouseHover += new System.EventHandler(this.LblAceptarMouseHover);
			// 
			// lblSizePredator
			// 
			this.lblSizePredator.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
			this.lblSizePredator.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lblSizePredator.Location = new System.Drawing.Point(195, 98);
			this.lblSizePredator.Name = "lblSizePredator";
			this.lblSizePredator.Size = new System.Drawing.Size(189, 23);
			this.lblSizePredator.TabIndex = 7;
			this.lblSizePredator.Text = "Depredador: ";
			this.lblSizePredator.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			// 
			// valuePredator
			// 
			this.valuePredator.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(30)))), ((int)(((byte)(20)))));
			this.valuePredator.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.valuePredator.ForeColor = System.Drawing.SystemColors.Info;
			this.valuePredator.Location = new System.Drawing.Point(236, 147);
			this.valuePredator.Maximum = new decimal(new int[] {
									70,
									0,
									0,
									0});
			this.valuePredator.Minimum = new decimal(new int[] {
									1,
									0,
									0,
									0});
			this.valuePredator.Name = "valuePredator";
			this.valuePredator.Size = new System.Drawing.Size(100, 34);
			this.valuePredator.TabIndex = 6;
			this.valuePredator.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.valuePredator.Value = new decimal(new int[] {
									5,
									0,
									0,
									0});
			// 
			// lbl
			// 
			this.lbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lbl.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lbl.Location = new System.Drawing.Point(0, 39);
			this.lbl.Name = "lbl";
			this.lbl.Size = new System.Drawing.Size(384, 23);
			this.lbl.TabIndex = 8;
			this.lbl.Text = "VELOCIDADES ACTUALES";
			this.lbl.TextAlign = System.Drawing.ContentAlignment.TopCenter;
			// 
			// Selection
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.ClientSize = new System.Drawing.Size(386, 308);
			this.Controls.Add(this.lbl);
			this.Controls.Add(this.lblSizePredator);
			this.Controls.Add(this.valuePredator);
			this.Controls.Add(this.lbltype);
			this.Controls.Add(this.lblClosed);
			this.Controls.Add(this.lblSizePrey);
			this.Controls.Add(this.lblOk);
			this.Controls.Add(this.valuePrey);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "Selection";
			this.Text = "overlayTree";
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseUp);
			((System.ComponentModel.ISupportInitialize)(this.valuePrey)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.valuePredator)).EndInit();
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Label lbl;
		private System.Windows.Forms.NumericUpDown valuePredator;
		private System.Windows.Forms.Label lblSizePredator;
		private System.Windows.Forms.Label lbltype;
		private System.Windows.Forms.Label lblClosed;
		private System.Windows.Forms.Label lblSizePrey;
		private System.Windows.Forms.Label lblOk;
		private System.Windows.Forms.NumericUpDown valuePrey;
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
		
		
		void LblAceptarMouseHover(object sender, EventArgs e) { lblOk.ForeColor = Color.Red; }
		void LblAceptarMouseLeave(object sender, EventArgs e) { lblOk.ForeColor = Color.White; }
	}
}
