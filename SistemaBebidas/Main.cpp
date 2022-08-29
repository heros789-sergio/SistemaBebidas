#include <iostream>
#include <string>
#include "UsuarioSesion.h"
#include "UsuarioVisitor.h"
#include "FunctorProductos.h"
#include "LoginForm.h"
#include "RegisterForm.h"
#include "ValidarJefeForm.h"
#include "JefeDeAlmacenForm.h"
#include "ControladorExpedicionForm.h"
#include "OperarioPedidosForm.h"
#include "PersonalDeVigilanciaForm.h"
#include "PuestoVigilanciaMostrar.h"
#include "RegistroDeIngreso.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::Data::SqlClient;
using namespace msclr::interop;

// Segun la clase, Se modifica el comportamiento de la funcion iniciar_sesion(),
// Abriendo un formulario diferente, dependiendo el usuarioVisitor
class JefeAlmacenVisitor:public UsuarioVisitor{
public:
	void accept(Visitor *);
	void iniciar_sesion(UsuarioVisitor* user, UsuarioSesion* datos){
		SistemaBebidas::JefeDeAlmacenForm JefeDeAlmacenSeccion(datos);
		Application::Run(% JefeDeAlmacenSeccion);
	}
};

class ControladorExpedicionVisitor:public UsuarioVisitor{
public:
	void accept(Visitor *);
	void iniciar_sesion(UsuarioVisitor* user, UsuarioSesion* datos){
		SistemaBebidas::ControladorExpedicionForm controladorExpedicionSeccion(datos);
		Application::Run(% controladorExpedicionSeccion);
	}
};

class OperarioPedidosVisitor:public UsuarioVisitor{
public:
	void accept(Visitor *);
	void iniciar_sesion(UsuarioVisitor* user, UsuarioSesion* datos){
		SistemaBebidas::OperarioPedidosForm operarioPedidosSeccion(datos);
		Application::Run(% operarioPedidosSeccion);
	}
};

class PuestoVigilanciaVisitor:public UsuarioVisitor{
public:
	void accept(Visitor *);
	void iniciar_sesion(UsuarioVisitor* user, UsuarioSesion* datos){
		SistemaBebidas::PersonalDeVigilanciaForm PersonalVigilanciaSeccion(datos);
		Application::Run(% PersonalVigilanciaSeccion);
	}
};

//Recibe el visitor (Clase que quiere modificar el comportamiento de iniciar_sesion())
class Visitor{ 
public:
	/*
	- virtual puro(=0) no se puede instanciar
	- Se usa sobrecarga de Funciones para visit() pues
	  Cada método visit, recibe punteros de diferentes clases
	*/
	virtual void visit(JefeAlmacenVisitor*) = 0;
	virtual void visit(ControladorExpedicionVisitor *) = 0;
	virtual void visit(OperarioPedidosVisitor *) = 0;	
	virtual void visit(PuestoVigilanciaVisitor *) = 0;
};

//Se redefine el metodo visit que antes estaba declarado como abstracto
class iniciar_sesion: public Visitor{ //Sobrecarga de Funciones
private:
	UsuarioVisitor* user;
	UsuarioSesion* datos;

public:
	iniciar_sesion(UsuarioSesion* datos){//constructor
		this->datos = datos;
	}
	//Sobrecarga de Funciones
	void visit(JefeAlmacenVisitor *a){ 
		a->iniciar_sesion(a, this->datos);
	}
	void visit(ControladorExpedicionVisitor *b){
		b->iniciar_sesion(b, this->datos);
	}
	void visit(OperarioPedidosVisitor *c){
		c->iniciar_sesion(c, this->datos);
	}
	void visit(PuestoVigilanciaVisitor *d){
		d->iniciar_sesion(d, this->datos);
	}
};

//Aplicamos los métodos visit de la clase visitor
void JefeAlmacenVisitor::accept(Visitor *v){
	v->visit(this);
}
void ControladorExpedicionVisitor::accept(Visitor *v){
	v->visit(this);
}
void OperarioPedidosVisitor::accept(Visitor *v){
	v->visit(this);
}
void PuestoVigilanciaVisitor::accept(Visitor *v){
	v->visit(this);
}


int main(){
	UsuarioSesion& user = UsuarioSesion::get_instance();
	UsuarioVisitor *set[] = {	new JefeAlmacenVisitor, 
								new ControladorExpedicionVisitor, 
								new OperarioPedidosVisitor,
								new PuestoVigilanciaVisitor};//creando espacio
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Usuario* user = nullptr;
	while (true) {
		SistemaBebidas::LoginForm^ login = gcnew SistemaBebidas::LoginForm();
		login->ShowDialog();
		if (login->switchToRegister) {
			SistemaBebidas::ValidarJefeForm^ validarJefeForm = gcnew SistemaBebidas::ValidarJefeForm;
			validarJefeForm->ShowDialog();
			if (validarJefeForm->validacionJefe) {
				SistemaBebidas::RegisterForm^ registerForm = gcnew SistemaBebidas::RegisterForm;
				registerForm->ShowDialog();

				if (registerForm->switchToLogin) {
					continue;
				}
				else {
					user = registerForm->user;
					break;
				}
			}
		}
		else {
			user = login->user;
			break;
		}
	}
	iniciar_sesion ad_visitor(&user); // Por referencia por el Singleton Pattern

	if(user.getPermiso() == "Jefe de Almacen"){
		set[0]->accept(&ad_visitor);		
	}
	else if(user.getPermiso() == "Controlador de Expedicion"){
		set[1]->accept(&ad_visitor);	
	}
	else if(user.getPermiso() == "Operario de Pedidos"){
		set[2]->accept(&ad_visitor);	
	}
	else if(user.getPermiso() == "Personal de Vigilancia"){
		set[3]->accept(&ad_visitor);	
	}

	//}
	//else {
		//listaProductos.get()->getInPosicion(0)->getDato().precio
		//String^ marca = gcnew String((listaProductos.get()->getInPosicion(0)->getDato().marca).data());
		//MessageBox::Show("Usted salio del sistema", "Sistema de Almacen de Bebidas", MessageBoxButtons::OK);
	//}
	//delete user;
}
