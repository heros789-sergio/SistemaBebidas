// Definicion de Funciones para UsuarioSesion => Singleton Pattern
#include "UsuarioSesion.h"

int UsuarioSesion::getId() const {
    return this->id;
}
std::string UsuarioSesion::getNombres() const {
    return this->nombres;
}
std::string UsuarioSesion::getApellidos() const {
    return this->apellidos;
}
std::string UsuarioSesion::getEmail() const {
    return this->email;
}
std::string UsuarioSesion::getUsuario() const {
    return this->usuario;
}
std::string UsuarioSesion::getPassword() const {
    return this->password;
}
std::string UsuarioSesion::getPermiso() const {
    return this->permiso;
}