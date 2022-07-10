/*
 * Creado por SharpDevelop.
 * Usuario: david
 * Fecha: 04/03/2020
 * Hora: 11:55 p. m.
 * 
 * Para cambiar esta plantilla use Herramientas | Opciones | Codificación | Editar Encabezados Estándar
 */
using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace ProyectPreyPredator {
	/// <summary>
	/// Description of overlayTree.
	/// </summary>
	public partial class Status : Form {
		public Status(List<Prey> prey, List<Predator> predator) {
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			preys = prey;
			predators = predator;
			listBoxFill();
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void listBoxFill() {
			int index = 0;
			/*lista de predadores*/
			foreach(Predator p in predators) {
				treeViewPredators.Nodes.Add("Depredador: " + p.Id);
				treeViewPredators.Nodes[index].Nodes.Add("Origen:  " + p.Origen);
				treeViewPredators.Nodes[index].Nodes.Add("Destino: " + p.Destino);
				treeViewPredators.Nodes[index].Nodes.Add("Presa:   " + (p.containPrey() ? ""+p.Prey.Id : " No"));
				treeViewPredators.Nodes[index].Nodes.Add("Euforia: " + p.Euforia);
				treeViewPredators.Nodes[index].Nodes.Add("Vel:     " + Predator.Speed);
				treeViewPredators.Nodes[index].Nodes.Add("Tamaño: " + p.Size);
				index++;
			}
			index = 0;
			/*lista de presas*/
			foreach(Prey p in preys) {
				treeViewPreys.Nodes.Add("Presa: " + p.Id);
				treeViewPreys.Nodes[index].Nodes.Add("Origen:    " + p.Origen);
				treeViewPreys.Nodes[index].Nodes.Add("Destino:   " + p.Destino);
				treeViewPreys.Nodes[index].Nodes.Add("Depredador " + (p.containPredator() ? ""+p.predator.Id: "No"));
				treeViewPreys.Nodes[index].Nodes.Add("Invisible: " + (p.invisible ? "Si" : "No"));
				treeViewPreys.Nodes[index].Nodes.Add("Vel:       " + Prey.Speed);
				treeViewPreys.Nodes[index].Nodes.Add("Vel. extra:" + p.survivor_speed);
				treeViewPreys.Nodes[index].Nodes.Add("Tamaño: " + p.Size);
				index++;
			}
			
		}
		

	}
}
