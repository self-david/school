/*
 * Created by SharpDevelop.
 * User: rs
 * Date: 12/05/2020
 * Time: 13H19
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;

namespace ProyectPreyPredator {
	/// <summary>
	/// Description of Dijstra.
	/// </summary>
	public class Node {
		public Vertex Vo;//vertice origen
		public Vertex Va;//vertice anterior
		public double Dt;//distancia total
		public bool finish;//definitivo
		
		public Node(Vertex origen) {
			Vo = origen;
			Va = null;
			Dt = Double.MaxValue;
			finish = false;
		}
		
		public Node() {}
		
		public void upDate(Vertex before, double distance) {
			Va = before;
			Dt = distance;			
		}
		
	}
	
	public class Dijstra {
		private Vertex Vo;
		private List<Node> vector;
		private int completes, g;
		private int[,] Matriz, m2;
		List<Vertex> listVertex;
		public float distancia;
		
		public Dijstra() { }
		
		public Dijstra(Graph g, int[,] m) {
			Matriz = m2 = new int[g.Vertexs.Count,g.Vertexs.Count];
			m2 = m;
			this.g = g.Vertexs.Count;
			listVertex = new List<Vertex>();
			saveVertex(g);
			generateMatriz();
			generarSubGrafo();
		}
		
		private void saveVertex(Graph g) {
			vector = new List<Node>();
			
			foreach(Vertex v in g.Vertexs) {
				vector.Add(new Node(v));
				listVertex.Add(v);
			}			
		}
		
		public void generarSubGrafo() {
			for(int i = 0; i < vector.Count; i++) {
				subGrafo(i);
			}
		}
		
		private void subGrafo(int vertex) {
			if(!listVertex[vertex].SubGrafo.Contains(vertex)) {
				listVertex[vertex].SubGrafo.Add(vertex);
				for(int j = 0; j < listVertex.Count; j++) {
					if(Matriz[vertex, j] == 1) {
						Matriz[vertex, j] = 0;
						Matriz[j, vertex] = 0;
						listVertex[j].SubGrafo = listVertex[vertex].SubGrafo;
						subGrafo(j);
					}
				}
			}
		}
		
		public void origen(Vertex origen) {
			Vo = origen;
			completes = 0;
		}
		
		private void generateMatriz() {
			for(int i = 0; i < listVertex.Count; i++) {
				for(int j = 0; j < listVertex.Count; j++) {
					Matriz[i,j] = m2[i,j];
				}
			}
		}
		
		public void roads() {
			List<Node> N = new List<Node>();
			foreach(Node n in vector) { 
				if(!listVertex[Vo.Id].SubGrafo.Contains(n.Vo.Id)) { 
					//vector.Remove(n);
					N.Add(n);
				}
			}
			foreach(Node n in N) { 
				vector.Remove(n);
			}
			Node node = new Node();
			node.Vo = Vo;
			//crea los caminos
			//inicializar....
			foreach(Node n in vector) {
				if(node.Vo == n.Vo) {
					n.Dt = 0;
					n.Va = node.Vo;
					break;
				}
			}
			
			while(!completed()) {
				//agrega nueva soluccion...
				if(!listVertex[Vo.Id].SubGrafo.Contains(node.Vo.Id)) {
					completes++;
					node.finish = true;
					continue;
				}
				node = addSoluction();
				//actualizar...
				upDate(node);
			}
		}
		
		private bool completed() {
			return completes == vector.Count;
		}
		
		private Node addSoluction() {
			Node node = new Node();
			node.Dt = Double.MaxValue;
			
			foreach(Node n in vector) {
				if(!Double.IsInfinity(n.Dt) && !n.finish) {
					if(n.Dt < node.Dt) {
						node = n;
					}
				}
			}
			
			//añado uno  completados
			node.finish = true;
			completes++;
			
			return node;
		}
		
		private void upDate(Node n) {
			int index;
			foreach(Edge e in n.Vo.Edges) {
				//busco el nodo destino
				index = vector.FindIndex(x => x.Vo == e.Destino);
				if(vector[index].Dt > n.Dt + e.Weight) {
					vector[index].upDate(e.Origen, n.Dt + e.Weight);
				}
				
			}
		}
		
		public List<Vertex> draw(Vertex v) {
			if(!listVertex[Vo.Id].SubGrafo.Contains(v.Id)) {
				return null;//no conexo
			}
			
			int index;
			Vertex v2 = new Vertex(v);
			List<Vertex> lv = new List<Vertex>();
			lv.Add(v);
			
			index = vector.FindIndex(x => x.Vo == v);
			distancia = 0;
			while(Vo != v2) {
				lv.Add(vector[index].Va);
				v2 = vector[index].Va;
				distancia += vector[index].Va.Circle.distance(vector[index].Vo.Circle);
				index = vector.FindIndex(x => x.Vo == vector[index].Va);
			}
			//recuperar distancias
			return lv;
		}		
		
	}
}
