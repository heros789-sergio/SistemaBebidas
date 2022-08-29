#pragma once
#include <string>
//Singleton Pattern
class UsuarioSesion{ //Funciona como variable de sesion del programa
private:
    int id;
    std::string nombres;
    std::string apellidos;
    std::string email;
    std::string usuario;
    std::string password;
    std::string permiso;
protected:
    UsuarioSesion() = default;
public:
    static UsuarioSesion& get_instance() { // Metodo Estatico de Instanciacion
        static UsuarioSesion instance;
        return instance;
    }
    // Guarda los datos en los atributos
    void setDatosUsuarioSingleton(int id, std::string nombres, std::string apellidos,
            std::string email, std::string usuario, std::string password, std::string permiso) {
        this->id = id;
        this->nombres = nombres;
        this->apellidos = apellidos;
        this->email = email;
        this->usuario = usuario;
        this->password = password;
        this->permiso = permiso;
    }
    // Getters (Solo lectura)
    int getId() const;
    std::string getNombres() const;
    std::string getApellidos() const;
    std::string getEmail() const;
    std::string getUsuario() const;
    std::string getPassword() const;
    std::string getPermiso() const;
};
