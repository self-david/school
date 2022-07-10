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
	public partial class Selection : Form {
		public Selection() {
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			lblSizePrey.Text += Prey.Speed.ToString();
			lblSizePredator.Text += Predator.Speed.ToString();
			valuePrey.Value = Prey.Speed;
			valuePredator.Value = Predator.Speed;
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		
		
		void LblOkClick(object sender, EventArgs e) {
			Prey.Speed = (int)valuePrey.Value;
			Predator.Speed = (int)valuePredator.Value;
			
			this.Close();
		}
	
		
	}
}
