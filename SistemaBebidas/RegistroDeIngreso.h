#pragma once
#include <msclr\marshal_cppstd.h>
#include "RegistroDeIngreso.h"
// **********
#include <memory>
#include "ArrayDinamicoRef.h"
#include "UsuarioVigilancia.h"
#include "FunctorVigilancia.h"
#include "FunctorVigilanciaSelecciona.h"
using std::stoi;

namespace SistemaBebidas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace msclr::interop;

	/// <summary>
	/// Resumen de RegistroDeIngreso
	/// </summary>
	public ref class RegistroDeIngreso : public System::Windows::Forms::Form
	{
	public:
		RegistroDeIngreso(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~RegistroDeIngreso()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnRegresar;
	private: System::Windows::Forms::Label^ DIA;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ data_grid;
	private: System::Windows::Forms::ComboBox^ filtro;
	private: System::Windows::Forms::TextBox^ Buscador;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ data_busqueda;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NOMBRE;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ APELLIDOS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PERMISO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ HORA;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FECHA;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->DIA = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->data_grid = (gcnew System::Windows::Forms::DataGridView());
			this->filtro = (gcnew System::Windows::Forms::ComboBox());
			this->Buscador = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->data_busqueda = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NOMBRE = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->APELLIDOS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PERMISO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HORA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FECHA = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_grid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_busqueda))->BeginInit();
			this->SuspendLayout();
			// 
			// btnRegresar
			// 
			this->btnRegresar->Location = System::Drawing::Point(892, 469);
			this->btnRegresar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(102, 41);
			this->btnRegresar->TabIndex = 33;
			this->btnRegresar->Text = L"REGRESAR";
			this->btnRegresar->UseVisualStyleBackColor = true;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &RegistroDeIngreso::btnRegresar_Click);
			// 
			// DIA
			// 
			this->DIA->AutoSize = true;
			this->DIA->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 16));
			this->DIA->Location = System::Drawing::Point(699, 167);
			this->DIA->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DIA->Name = L"DIA";
			this->DIA->Size = System::Drawing::Size(0, 22);
			this->DIA->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(82, 20);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(784, 35);
			this->label1->TabIndex = 25;
			this->label1->Text = L"REGISTRO DE ENTRADA Y SALIDA DE USUARIOS";
			// 
			// data_grid
			// 
			this->data_grid->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->data_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_grid->Location = System::Drawing::Point(28, 80);
			this->data_grid->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->data_grid->Name = L"data_grid";
			this->data_grid->RowHeadersWidth = 51;
			this->data_grid->RowTemplate->Height = 24;
			this->data_grid->Size = System::Drawing::Size(720, 249);
			this->data_grid->TabIndex = 24;
			// 
			// filtro
			// 
			this->filtro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->filtro->FormattingEnabled = true;
			this->filtro->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"ID", L"NOMBRE", L"APELLIDOS", L"PERMISO", L"HORA",
					L"FECHA"
			});
			this->filtro->Location = System::Drawing::Point(824, 121);
			this->filtro->Name = L"filtro";
			this->filtro->Size = System::Drawing::Size(148, 28);
			this->filtro->TabIndex = 53;
			this->filtro->SelectedIndexChanged += gcnew System::EventHandler(this, &RegistroDeIngreso::filtro_SelectedIndexChanged);
			// 
			// Buscador
			// 
			this->Buscador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->Buscador->Location = System::Drawing::Point(824, 194);
			this->Buscador->Name = L"Buscador";
			this->Buscador->Size = System::Drawing::Size(148, 27);
			this->Buscador->TabIndex = 52;
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::White;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 10, System::Drawing::FontStyle::Bold));
			this->btnBuscar->Location = System::Drawing::Point(824, 266);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(147, 30);
			this->btnBuscar->TabIndex = 51;
			this->btnBuscar->Text = L"BUSCAR";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &RegistroDeIngreso::btnBuscar_Click);
			// 
			// data_busqueda
			// 
			this->data_busqueda->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->data_busqueda->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_busqueda->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->NOMBRE,
					this->APELLIDOS, this->PERMISO, this->HORA, this->FECHA
			});
			this->data_busqueda->Location = System::Drawing::Point(28, 375);
			this->data_busqueda->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->data_busqueda->Name = L"data_busqueda";
			this->data_busqueda->RowHeadersWidth = 51;
			this->data_busqueda->RowTemplate->Height = 24;
			this->data_busqueda->Size = System::Drawing::Size(805, 136);
			this->data_busqueda->TabIndex = 54;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			this->ID->Width = 125;
			// 
			// NOMBRE
			// 
			this->NOMBRE->HeaderText = L"NOMBRE";
			this->NOMBRE->MinimumWidth = 6;
			this->NOMBRE->Name = L"NOMBRE";
			this->NOMBRE->Width = 125;
			// 
			// APELLIDOS
			// 
			this->APELLIDOS->HeaderText = L"APELLIDOS";
			this->APELLIDOS->MinimumWidth = 6;
			this->APELLIDOS->Name = L"APELLIDOS";
			this->APELLIDOS->Width = 125;
			// 
			// PERMISO
			// 
			this->PERMISO->HeaderText = L"PERMISO";
			this->PERMISO->MinimumWidth = 6;
			this->PERMISO->Name = L"PERMISO";
			this->PERMISO->Width = 125;
			// 
			// HORA
			// 
			this->HORA->HeaderText = L"HORA";
			this->HORA->MinimumWidth = 6;
			this->HORA->Name = L"HORA";
			this->HORA->Width = 125;
			// 
			// FECHA
			// 
			this->FECHA->HeaderText = L"FECHA";
			this->FECHA->MinimumWidth = 6;
			this->FECHA->Name = L"FECHA";
			this->FECHA->Width = 125;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14));
			this->label2->Location = System::Drawing::Point(36, 341);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 19);
			this->label2->TabIndex = 55;
			this->label2->Text = L"BUSQUEDA:";
			// 
			// RegistroDeIngreso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1015, 521);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->data_busqueda);
			this->Controls->Add(this->filtro);
			this->Controls->Add(this->Buscador);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->btnRegresar);
			this->Controls->Add(this->DIA);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->data_grid);
			this->Name = L"RegistroDeIngreso";
			this->Text = L"RegistroDeIngreso";
			this->Load += gcnew System::EventHandler(this, &RegistroDeIngreso::RegistroDeIngreso_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_grid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_busqueda))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RegistroDeIngreso_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Consulta();
	}
	public: void Consulta() {
		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=sistemabebidas;Integrated Security=True";
		SqlConnection sqlConn(connString); //se crea el objeto conexion
		sqlConn.Open();
		String^ sqlQuery = "SELECT ID , NOMBRE , APELLIDOS , PERMISO , HORA, FECHA  FROM vigilancia ";
		SqlCommand^ cursor = gcnew SqlCommand(sqlQuery, % sqlConn);
		SqlDataAdapter^ data = gcnew SqlDataAdapter(cursor);

		DataTable^ tabla = gcnew DataTable();
		data->Fill(tabla);
		this->data_grid->DataSource = tabla;
		sqlConn.Close();
	}


	private: System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filtro = this->filtro->Text;
		String^ nombreB = this->Buscador->Text;

		FunctorVigilanciaSelecciona obtenerTodosLosRegistros;
		std::shared_ptr<ArrayDinamicoRef<UsuarioVi>> registrosEncontrados = obtenerTodosLosRegistros(filtro,nombreB);

		data_busqueda->Rows->Clear();
		int id = 0;
		String^ nombre = "";
		String^ apellidos = "";
		String^ permiso = "";
		String^ hora = "";
		String^ fecha = "";

		int n = 0;
		int conta = 0;

		int auxiliar = 0;
	
		for (int i = 0; i < registrosEncontrados->getSize(); i++) {
			int id = registrosEncontrados.get()->getInPosicion(i)->getDato().id;
			String^ nombre = gcnew String((registrosEncontrados.get()->getInPosicion(i)->getDato().nombre).data());
			String^ apellidos = gcnew String((registrosEncontrados.get()->getInPosicion(i)->getDato().permiso).data());
			String^ permiso = gcnew String((registrosEncontrados.get()->getInPosicion(i)->getDato().apellidos).data());
			String^ hora = gcnew String((registrosEncontrados.get()->getInPosicion(i)->getDato().hora).data());
			String^ fecha = gcnew String((registrosEncontrados.get()->getInPosicion(i)->getDato().fecha).data());
			//registro = gcnew String((ListaUsuario.get()->getInPosicion(i)->getDato().registro).data());
			data_busqueda->Rows->Add();

			data_busqueda->Rows[auxiliar]->Cells[0]->Value = id;
			data_busqueda->Rows[auxiliar]->Cells[1]->Value = nombre;
			data_busqueda->Rows[auxiliar]->Cells[2]->Value = apellidos;
			data_busqueda->Rows[auxiliar]->Cells[3]->Value = permiso;
			data_busqueda->Rows[auxiliar]->Cells[4]->Value = hora;
			data_busqueda->Rows[auxiliar]->Cells[5]->Value = fecha;
			auxiliar++;
		}
	}
	private: System::Void filtro_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
