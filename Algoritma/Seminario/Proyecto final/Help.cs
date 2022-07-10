/*
 * Creado por SharpDevelop.
 * Usuario: david
 * Fecha: 04/03/2020
 * Hora: 11:55 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
using System;
using System.Windows.Forms;

namespace ProyectPreyPredator {
	/// <summary>
	/// Description of overlayTree.
	/// </summary>
	public partial class Help : Form {
		public Help() {
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
		}
		
		void PreyDescripcionClick(object sender, EventArgs e) {
			tabControl.SelectedIndex = 0;
		}
		
		void PredatorDEscripcionClick(object sender, EventArgs e) {
			tabControl.SelectedIndex = 1;
		}

		
		void CherryDescripcionClick(object sender, EventArgs e) {
			tabControl.SelectedIndex = 2;
		}
		
		void FileDescripcionClick(object sender, EventArgs e) {
			tabControl.SelectedIndex = 3;
		}
		
		void OptionDescriptionClick(object sender, EventArgs e) {
			tabControl.SelectedIndex = 4;
		}
	}
}
