#pragma once
#include "AccesoSubject.h"
#include "RealAccesoSubject.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

class AccesoProxy : public AccesoSubject
{
private:
    bool Acceso; //Atributo que guardara el acceso del proxy
	RealAccesoSubject* real_subject_; //Usa el RealAccesoSubject para usar SolicitudAcceso
public:
    AccesoProxy(RealAccesoSubject* real_subject, String^ usuarioInput, String^ passwordInput) {
        this->real_subject_ = real_subject;
        this->Acceso = false;
        if (usuarioInput->Length != 0 && passwordInput->Length != 0) { //Verifica inputs vacios
            this->Acceso = true;
        }
    }
    ~AccesoProxy() { }
    bool SolicitudAcceso() override { //Polimorfismo para redefinir la funcion con las 2 validaciones
        if ((this->Acceso == true) && (this->real_subject_->SolicitudAcceso() == true)) {
            return true;
        }
        else {
            return false;
        }
    }
};


