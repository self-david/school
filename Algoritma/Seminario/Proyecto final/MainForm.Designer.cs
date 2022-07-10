/*
 * Creado por SharpDevelop.
 * Usuario: dagur
 * Fecha: 03/03/2020
 * Hora: 08:00 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
 
using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace ProyectPreyPredator {
	partial class MainForm {
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
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
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.lblMinimized = new System.Windows.Forms.Label();
			this.lblMaximized = new System.Windows.Forms.Label();
			this.lblClosed = new System.Windows.Forms.Label();
			this.panelSize = new System.Windows.Forms.Panel();
			this.openFileImage = new System.Windows.Forms.OpenFileDialog();
			this.tabSecond = new System.Windows.Forms.TabPage();
			this.pictureBoxMap = new System.Windows.Forms.PictureBox();
			this.tabInit = new System.Windows.Forms.TabPage();
			this.pictureBoxImage = new System.Windows.Forms.PictureBox();
			this.tabControl = new System.Windows.Forms.TabControl();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.loadImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.saveImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
			this.exitToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
			this.opcionesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.MenuItemAnimar = new System.Windows.Forms.ToolStripMenuItem();
			this.MenuItemDestiny = new System.Windows.Forms.ToolStripMenuItem();
			this.cerezasToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
			this.velocidadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.verEstadosToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.ayudaToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
			this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
			this.timer = new System.Windows.Forms.Timer(this.components);
			this.panelSize.SuspendLayout();
			this.tabSecond.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxMap)).BeginInit();
			this.tabInit.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxImage)).BeginInit();
			this.tabControl.SuspendLayout();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// lblMinimized
			// 
			this.lblMinimized.BackColor = System.Drawing.Color.Transparent;
			this.lblMinimized.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblMinimized.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblMinimized.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lblMinimized.Location = new System.Drawing.Point(0, -4);
			this.lblMinimized.Name = "lblMinimized";
			this.lblMinimized.Size = new System.Drawing.Size(29, 34);
			this.lblMinimized.TabIndex = 1;
			this.lblMinimized.Text = "__";
			this.lblMinimized.TextAlign = System.Drawing.ContentAlignment.BottomLeft;
			this.lblMinimized.Click += new System.EventHandler(this.LblMinimizedClick);
			// 
			// lblMaximized
			// 
			this.lblMaximized.BackColor = System.Drawing.Color.Transparent;
			this.lblMaximized.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblMaximized.Font = new System.Drawing.Font("Microsoft Sans Serif", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblMaximized.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.lblMaximized.Location = new System.Drawing.Point(37, -1);
			this.lblMaximized.Name = "lblMaximized";
			this.lblMaximized.Size = new System.Drawing.Size(39, 34);
			this.lblMaximized.TabIndex = 2;
			this.lblMaximized.Text = "■";
			this.lblMaximized.Click += new System.EventHandler(this.MaximizedClick);
			// 
			// lblClosed
			// 
			this.lblClosed.BackColor = System.Drawing.Color.Transparent;
			this.lblClosed.Cursor = System.Windows.Forms.Cursors.Hand;
			this.lblClosed.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblClosed.ForeColor = System.Drawing.Color.Red;
			this.lblClosed.Location = new System.Drawing.Point(83, 0);
			this.lblClosed.Name = "lblClosed";
			this.lblClosed.Size = new System.Drawing.Size(25, 34);
			this.lblClosed.TabIndex = 3;
			this.lblClosed.Text = "x";
			this.lblClosed.Click += new System.EventHandler(this.ClosedClick);
			// 
			// panelSize
			// 
			this.panelSize.Controls.Add(this.lblMinimized);
			this.panelSize.Controls.Add(this.lblClosed);
			this.panelSize.Controls.Add(this.lblMaximized);
			this.panelSize.Location = new System.Drawing.Point(460, -6);
			this.panelSize.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.panelSize.Name = "panelSize";
			this.panelSize.Size = new System.Drawing.Size(120, 34);
			this.panelSize.TabIndex = 4;
			// 
			// openFileImage
			// 
			this.openFileImage.FileName = "file";
			// 
			// tabSecond
			// 
			this.tabSecond.Controls.Add(this.pictureBoxMap);
			this.tabSecond.Location = new System.Drawing.Point(4, 34);
			this.tabSecond.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.tabSecond.Name = "tabSecond";
			this.tabSecond.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.tabSecond.Size = new System.Drawing.Size(389, 367);
			this.tabSecond.TabIndex = 1;
			this.tabSecond.Text = "Mapa";
			this.tabSecond.UseVisualStyleBackColor = true;
			// 
			// pictureBoxMap
			// 
			this.pictureBoxMap.Location = new System.Drawing.Point(0, 0);
			this.pictureBoxMap.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.pictureBoxMap.Name = "pictureBoxMap";
			this.pictureBoxMap.Size = new System.Drawing.Size(387, 370);
			this.pictureBoxMap.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
			this.pictureBoxMap.TabIndex = 0;
			this.pictureBoxMap.TabStop = false;
			this.pictureBoxMap.MouseClick += new System.Windows.Forms.MouseEventHandler(this.PictureBoxMouseClick);
			this.pictureBoxMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.PictureBoxMouseMove);
			// 
			// tabInit
			// 
			this.tabInit.Controls.Add(this.pictureBoxImage);
			this.tabInit.Location = new System.Drawing.Point(4, 34);
			this.tabInit.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.tabInit.Name = "tabInit";
			this.tabInit.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.tabInit.Size = new System.Drawing.Size(389, 367);
			this.tabInit.TabIndex = 0;
			this.tabInit.Text = "Imagen";
			this.tabInit.UseVisualStyleBackColor = true;
			// 
			// pictureBoxImage
			// 
			this.pictureBoxImage.BackColor = System.Drawing.Color.Transparent;
			this.pictureBoxImage.Cursor = System.Windows.Forms.Cursors.Default;
			this.pictureBoxImage.Location = new System.Drawing.Point(0, 0);
			this.pictureBoxImage.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.pictureBoxImage.Name = "pictureBoxImage";
			this.pictureBoxImage.Size = new System.Drawing.Size(387, 370);
			this.pictureBoxImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
			this.pictureBoxImage.TabIndex = 0;
			this.pictureBoxImage.TabStop = false;
			// 
			// tabControl
			// 
			this.tabControl.Controls.Add(this.tabInit);
			this.tabControl.Controls.Add(this.tabSecond);
			this.tabControl.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.tabControl.Location = new System.Drawing.Point(11, 34);
			this.tabControl.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.tabControl.Name = "tabControl";
			this.tabControl.SelectedIndex = 0;
			this.tabControl.Size = new System.Drawing.Size(397, 405);
			this.tabControl.TabIndex = 0;
			// 
			// menuStrip1
			// 
			this.menuStrip1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.fileToolStripMenuItem,
									this.opcionesToolStripMenuItem,
									this.ayudaToolStripMenuItem1});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
			this.menuStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional;
			this.menuStrip1.Size = new System.Drawing.Size(715, 31);
			this.menuStrip1.TabIndex = 9;
			this.menuStrip1.Text = "menuStrip1";
			this.menuStrip1.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.MenuMouseDoubleClick);
			this.menuStrip1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MenuMouseDown);
			this.menuStrip1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MenuMouseMove);
			this.menuStrip1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MenuMouseUp);
			// 
			// fileToolStripMenuItem
			// 
			this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.loadImageToolStripMenuItem,
									this.saveImageToolStripMenuItem,
									this.toolStripSeparator3,
									this.exitToolStripMenuItem1});
			this.fileToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.fileToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
			this.fileToolStripMenuItem.Size = new System.Drawing.Size(83, 27);
			this.fileToolStripMenuItem.Text = "&Archivo";
			// 
			// loadImageToolStripMenuItem
			// 
			this.loadImageToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.loadImageToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.loadImageToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.loadImageToolStripMenuItem.Name = "loadImageToolStripMenuItem";
			this.loadImageToolStripMenuItem.Size = new System.Drawing.Size(214, 28);
			this.loadImageToolStripMenuItem.Text = "Importar Mapa";
			this.loadImageToolStripMenuItem.Click += new System.EventHandler(this.MenuImportMap);
			// 
			// saveImageToolStripMenuItem
			// 
			this.saveImageToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.saveImageToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.saveImageToolStripMenuItem.Name = "saveImageToolStripMenuItem";
			this.saveImageToolStripMenuItem.Size = new System.Drawing.Size(214, 28);
			this.saveImageToolStripMenuItem.Text = "Exportar Imagen";
			this.saveImageToolStripMenuItem.Click += new System.EventHandler(this.MenuSaveImage);
			// 
			// toolStripSeparator3
			// 
			this.toolStripSeparator3.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.toolStripSeparator3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.toolStripSeparator3.Margin = new System.Windows.Forms.Padding(0, -1, 0, -1);
			this.toolStripSeparator3.Name = "toolStripSeparator3";
			this.toolStripSeparator3.RightToLeft = System.Windows.Forms.RightToLeft.No;
			this.toolStripSeparator3.Size = new System.Drawing.Size(211, 6);
			// 
			// exitToolStripMenuItem1
			// 
			this.exitToolStripMenuItem1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.exitToolStripMenuItem1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.exitToolStripMenuItem1.Name = "exitToolStripMenuItem1";
			this.exitToolStripMenuItem1.Size = new System.Drawing.Size(214, 28);
			this.exitToolStripMenuItem1.Text = "Salir";
			this.exitToolStripMenuItem1.Click += new System.EventHandler(this.MenuExit);
			// 
			// opcionesToolStripMenuItem
			// 
			this.opcionesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.MenuItemAnimar,
									this.MenuItemDestiny,
									this.cerezasToolStripMenuItem,
									this.toolStripMenuItem1,
									this.velocidadToolStripMenuItem,
									this.verEstadosToolStripMenuItem});
			this.opcionesToolStripMenuItem.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.opcionesToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.opcionesToolStripMenuItem.Name = "opcionesToolStripMenuItem";
			this.opcionesToolStripMenuItem.Size = new System.Drawing.Size(95, 27);
			this.opcionesToolStripMenuItem.Text = "Opciones";
			// 
			// MenuItemAnimar
			// 
			this.MenuItemAnimar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.MenuItemAnimar.CheckOnClick = true;
			this.MenuItemAnimar.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.MenuItemAnimar.Name = "MenuItemAnimar";
			this.MenuItemAnimar.Size = new System.Drawing.Size(192, 28);
			this.MenuItemAnimar.Text = "Animar";
			this.MenuItemAnimar.Click += new System.EventHandler(this.MenuAnimate);
			// 
			// MenuItemDestiny
			// 
			this.MenuItemDestiny.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.MenuItemDestiny.CheckOnClick = true;
			this.MenuItemDestiny.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.MenuItemDestiny.Name = "MenuItemDestiny";
			this.MenuItemDestiny.Size = new System.Drawing.Size(192, 28);
			this.MenuItemDestiny.Text = "Elegir Destino";
			this.MenuItemDestiny.Click += new System.EventHandler(this.MenuCreateDestiny);
			// 
			// cerezasToolStripMenuItem
			// 
			this.cerezasToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.cerezasToolStripMenuItem.CheckOnClick = true;
			this.cerezasToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.cerezasToolStripMenuItem.Name = "cerezasToolStripMenuItem";
			this.cerezasToolStripMenuItem.Size = new System.Drawing.Size(192, 28);
			this.cerezasToolStripMenuItem.Text = "Cerezas";
			this.cerezasToolStripMenuItem.Click += new System.EventHandler(this.MenuCherrys);
			// 
			// toolStripMenuItem1
			// 
			this.toolStripMenuItem1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.toolStripMenuItem1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.toolStripMenuItem1.Name = "toolStripMenuItem1";
			this.toolStripMenuItem1.Size = new System.Drawing.Size(192, 28);
			this.toolStripMenuItem1.Text = "Eliminar";
			this.toolStripMenuItem1.Click += new System.EventHandler(this.MenuDeleteEntity);
			// 
			// velocidadToolStripMenuItem
			// 
			this.velocidadToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.velocidadToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.velocidadToolStripMenuItem.Name = "velocidadToolStripMenuItem";
			this.velocidadToolStripMenuItem.Size = new System.Drawing.Size(192, 28);
			this.velocidadToolStripMenuItem.Text = "Velocidad";
			this.velocidadToolStripMenuItem.Click += new System.EventHandler(this.MenuSpeed);
			// 
			// verEstadosToolStripMenuItem
			// 
			this.verEstadosToolStripMenuItem.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.verEstadosToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.verEstadosToolStripMenuItem.Name = "verEstadosToolStripMenuItem";
			this.verEstadosToolStripMenuItem.Size = new System.Drawing.Size(192, 28);
			this.verEstadosToolStripMenuItem.Text = "Ver Estados";
			this.verEstadosToolStripMenuItem.Click += new System.EventHandler(this.MenuShowStatus);
			// 
			// ayudaToolStripMenuItem1
			// 
			this.ayudaToolStripMenuItem1.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Bold);
			this.ayudaToolStripMenuItem1.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
			this.ayudaToolStripMenuItem1.Name = "ayudaToolStripMenuItem1";
			this.ayudaToolStripMenuItem1.Size = new System.Drawing.Size(73, 27);
			this.ayudaToolStripMenuItem1.Text = "Ayuda";
			this.ayudaToolStripMenuItem1.Click += new System.EventHandler(this.MenuItemHelp);
			// 
			// timer
			// 
			this.timer.Interval = 33;
			this.timer.Tick += new System.EventHandler(this.TimerTick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(20)))), ((int)(((byte)(20)))), ((int)(((byte)(30)))));
			this.ClientSize = new System.Drawing.Size(715, 516);
			this.Controls.Add(this.panelSize);
			this.Controls.Add(this.tabControl);
			this.Controls.Add(this.menuStrip1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.MainMenuStrip = this.menuStrip1;
			this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
			this.Name = "MainForm";
			this.Text = "ProyectPreyPredator";
			this.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseDoubleClick);
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseUp);
			this.Resize += new System.EventHandler(this.MainFormResize);
			this.panelSize.ResumeLayout(false);
			this.tabSecond.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxMap)).EndInit();
			this.tabInit.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.pictureBoxImage)).EndInit();
			this.tabControl.ResumeLayout(false);
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.ToolStripMenuItem ayudaToolStripMenuItem1;
		private System.Windows.Forms.ToolStripMenuItem cerezasToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem MenuItemDestiny;
		private System.Windows.Forms.ToolStripMenuItem MenuItemAnimar;
		private System.Windows.Forms.Timer timer;
		private System.Windows.Forms.ToolStripMenuItem verEstadosToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem velocidadToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
		private System.Windows.Forms.SaveFileDialog saveFileDialog;
		private System.Windows.Forms.ToolStripMenuItem opcionesToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem saveImageToolStripMenuItem;
		private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
		private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem1;
		private System.Windows.Forms.ToolStripMenuItem loadImageToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.OpenFileDialog openFileImage;
		private System.Windows.Forms.PictureBox pictureBoxMap;
		private System.Windows.Forms.PictureBox pictureBoxImage;
		private System.Windows.Forms.Panel panelSize;
		private System.Windows.Forms.Label lblClosed;
		private System.Windows.Forms.Label lblMaximized;
		private System.Windows.Forms.Label lblMinimized;
		private System.Windows.Forms.TabPage tabSecond;
		private System.Windows.Forms.TabPage tabInit;
		private System.Windows.Forms.TabControl tabControl;
		///////////////////////////////////////////////////
		int mov, movX, movY;
		Engine engine;
		private System.Drawing.Bitmap bmpForeGround;
		private System.Drawing.Bitmap bmpBackGround;
		private System.Drawing.Bitmap bmpSave;
		private Figure circle = new Figure();
		Graph graph = new Graph();
		Dijstra dijstra;
		private int[,] Matriz;
		int i = 0;
		
		private SolidBrush brush = new SolidBrush(Color.FromArgb(255, (byte)20, (byte)20, (byte)30));
		
		private const int
		    HTLEFT = 10,
		    HTRIGHT = 11,
		    HTTOP = 12,
		    HTTOPLEFT = 13,
		    HTTOPRIGHT = 14,
		    HTBOTTOM = 15,
		    HTBOTTOMLEFT = 16,
		    HTBOTTOMRIGHT = 17;

		const int _ = 5; // you can rename this variable if you like
		
	   protected override void OnPaint(PaintEventArgs e) {// you can safely omit this method if you want
		    e.Graphics.FillRectangle(brush, Top);
		    e.Graphics.FillRectangle(brush, Left);
		    e.Graphics.FillRectangle(brush, Right);
		    e.Graphics.FillRectangle(brush, Bottom);
		}


		Rectangle Top { get { return new Rectangle(0, 0, this.ClientSize.Width, _); } }
		Rectangle Left { get { return new Rectangle(0, 0, _, this.ClientSize.Height); } }
		Rectangle Bottom { get { return new Rectangle(0, this.ClientSize.Height - _, this.ClientSize.Width, _); } }
		Rectangle Right { get { return new Rectangle(this.ClientSize.Width - _, 0, _, this.ClientSize.Height); } }
		
		Rectangle TopLeft { get { return new Rectangle(0, 0, _, _); } }
		Rectangle TopRight { get { return new Rectangle(this.ClientSize.Width - _, 0, _, _); } }
		Rectangle BottomLeft { get { return new Rectangle(0, this.ClientSize.Height - _, _, _); } }
		Rectangle BottomRight { get { return new Rectangle(this.ClientSize.Width - _, this.ClientSize.Height - _, _, _); } }


		protected override void WndProc(ref Message message) {
		    base.WndProc(ref message);
		
		    if (message.Msg == 0x84) {// WM_NCHITTEST
		        var cursor = this.PointToClient(Cursor.Position);
		
		        if (TopLeft.Contains(cursor)) message.Result = (IntPtr)HTTOPLEFT;
			   else if (TopRight.Contains(cursor)) message.Result = (IntPtr)HTTOPRIGHT;
			   else if (BottomLeft.Contains(cursor)) message.Result = (IntPtr)HTBOTTOMLEFT;
			   else if (BottomRight.Contains(cursor)) message.Result = (IntPtr)HTBOTTOMRIGHT;
			
			   else if (Top.Contains(cursor)) message.Result = (IntPtr)HTTOP;
			   else if (Left.Contains(cursor)) message.Result = (IntPtr)HTLEFT;
			   else if (Right.Contains(cursor)) message.Result = (IntPtr)HTRIGHT;
			   else if (Bottom.Contains(cursor)) message.Result = (IntPtr)HTBOTTOM;
		    }
		}
		
		
		
		void ClosedClick(object sender, EventArgs e) { Application.Exit(); }
		void MaximizedClick(object sender, EventArgs e) {
			if(this.WindowState == FormWindowState.Maximized)
				this.WindowState = FormWindowState.Normal;
			else
				this.WindowState = FormWindowState.Maximized;
		}
		void LblMinimizedClick(object sender, EventArgs e) { this.WindowState = FormWindowState.Minimized; }
		
		
		void MainFormMouseDoubleClick(object sender, MouseEventArgs e) {
			if(this.WindowState == FormWindowState.Maximized)
				this.WindowState = FormWindowState.Normal;
			else
				this.WindowState = FormWindowState.Maximized;
		}
		void MainFormMouseDown(object sender, MouseEventArgs e) {
			mov = 1;
			movX = e.X;
			movY = e.Y;
		}
		void MainFormMouseMove(object sender, MouseEventArgs e) {
			if(mov == 1)
				this.SetDesktopLocation(MousePosition.X-movX, MousePosition.Y-movY);
		}
		void MainFormMouseUp(object sender, MouseEventArgs e) {
			mov = 0;
		}
		
		
		void MenuMouseDoubleClick(object sender, MouseEventArgs e) {
			if(this.WindowState == FormWindowState.Maximized)
				this.WindowState = FormWindowState.Normal;
			else
				this.WindowState = FormWindowState.Maximized;
		}
		void MenuMouseDown(object sender, MouseEventArgs e) {
			mov = 1;
			movX = e.X;
			movY = e.Y;
		}
		void MenuMouseMove(object sender, MouseEventArgs e) {
			if(mov == 1)
				this.SetDesktopLocation(MousePosition.X-movX, MousePosition.Y-movY);
		}
		void MenuMouseUp(object sender, MouseEventArgs e) {
			mov = 0;
		}
		
		void MenuExit(object sender, EventArgs e) {
			Application.Exit();
		}
		
		void resize() {
			//tab
			tabControl.Width  = this.Width  - 20;
			tabControl.Height = this.Height - 40;
			
			//picturebox
			pictureBoxImage.Width    = tabControl.Width - 20;
			pictureBoxImage.Height   = tabControl.Height- 30;
			pictureBoxMap.Width  = tabControl.Width - 20;
			pictureBoxMap.Height = tabControl.Height- 30;
			
			//closed
			panelSize.Location = new Point(this.Width - 90, 0);
			
		}
		
		void MainFormResize(object sender, EventArgs e) {
			resize();
		}
		
		
		Point ajustarZoom(MouseEventArgs e) {
			int X, Y;
			int w_i = pictureBoxMap.Image.Width; 
            int h_i = pictureBoxMap.Image.Height;
            int w_c = pictureBoxMap.Width;
            int h_c = pictureBoxMap.Height;
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
		
		
	}
}
