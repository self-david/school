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
	partial class Status {
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
			this.lblClosed = new System.Windows.Forms.Label();
			this.treeViewPreys = new System.Windows.Forms.TreeView();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.treeViewPredators = new System.Windows.Forms.TreeView();
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
			// treeViewPreys
			// 
			this.treeViewPreys.Location = new System.Drawing.Point(12, 73);
			this.treeViewPreys.Name = "treeViewPreys";
			this.treeViewPreys.Size = new System.Drawing.Size(238, 294);
			this.treeViewPreys.TabIndex = 8;
			// 
			// label1
			// 
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.label1.Location = new System.Drawing.Point(12, 32);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(238, 29);
			this.label1.TabIndex = 9;
			this.label1.Text = "PRESAS";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// label2
			// 
			this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.label2.Location = new System.Drawing.Point(271, 32);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(238, 29);
			this.label2.TabIndex = 11;
			this.label2.Text = "DEPREDADORES";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// treeViewPredators
			// 
			this.treeViewPredators.Location = new System.Drawing.Point(271, 73);
			this.treeViewPredators.Name = "treeViewPredators";
			this.treeViewPredators.Size = new System.Drawing.Size(238, 294);
			this.treeViewPredators.TabIndex = 10;
			// 
			// Status
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.ClientSize = new System.Drawing.Size(524, 379);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.treeViewPredators);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.treeViewPreys);
			this.Controls.Add(this.lblClosed);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "Status";
			this.Text = "overlayTree";
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.OverlayTreeMouseUp);
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.TreeView treeViewPredators;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TreeView treeViewPreys;
		private System.Windows.Forms.Label lblClosed;
		int mov, movX, movY;
		System.Collections.Generic.List<Prey> preys = new System.Collections.Generic.List<Prey>();
		System.Collections.Generic.List<Predator> predators = new System.Collections.Generic.List<Predator>();
		
		
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
