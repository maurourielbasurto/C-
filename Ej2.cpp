/**
 * @file Untitled-1
 * @author Mauro Uriel Basurto Chavez (maurourielbasurto@gmail.com)
 * @brief Ejercoicio 2. Agenda de contactos 
 * @version 0.1
 * @date 2025-10-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contacto
{
private:
    string nombre;
    string telefono;

public:
    Contacto(string nombre, string telefono)
    {
        this->nombre = nombre;
        this->telefono = telefono;
    }

    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }

    void setNombre(string nombre) { this->nombre = nombre; }
    void setTelefono(string telefono) { this->telefono = telefono; }

    void mostrardatos() const
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Telefono: " << telefono << endl;
    }
};

class Agenda
{
private:
    vector<Contacto> contactos;

public:
    void agregarContacto(const Contacto& contacto)
    {
        contactos.push_back(contacto);
    }

    bool eliminarContacto()
    {
        if (!contactos.empty())
        {
            contactos.pop_back();
            return true;
        }
        return false;
    }

    vector<Contacto> buscarPorNombre(const string& nombre) const
    {
        vector<Contacto> resultados;
        for (const auto& c : contactos)
        {
            if (c.getNombre() == nombre)
                resultados.push_back(c);
        }
        return resultados;
    }

    vector<Contacto> buscarPorTelefono(const string& telefono) const
    {
        vector<Contacto> resultados;
        for (const auto& c : contactos)
        {
            if (c.getTelefono() == telefono)
                resultados.push_back(c);
        }
        return resultados;
    }

    vector<Contacto> listarContactos() const
    {
        return contactos;
    }

    bool vacia() const
    {
        return contactos.empty();
    }

    void mostrarAgenda() const
    {
        if (contactos.empty())
        {
            cout << "La agenda está vacía." << endl;
            return;
        }

        cout << "=== Agenda de Contactos ===" << endl;
        for (const auto& c : contactos)
        {
            c.mostrardatos();
        }
    }
};

int main()
{
    Agenda agenda;

    Contacto a("Pablito", "5535174603");
    Contacto b("Eduar", "5538849920");
    Contacto c("Mike", "5533700991");

    agenda.agregarContacto(a);
    agenda.agregarContacto(b);
    agenda.agregarContacto(c);

    cout << "Agenda:\n";
    agenda.mostrarAgenda();

    cout << "\nEliminando ultimo contacto...\n";
    if (agenda.eliminarContacto())
        cout << "Contacto eliminado.\n";
    else
        cout << "La agenda está vacía, no hay nada que eliminar.\n";

    cout << "\nAgenda final:\n";
    agenda.mostrarAgenda();

    return 0;
}
