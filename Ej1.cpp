/**
 * @file Ej1.cpp
 * @author Mauro Uriel Basurto Chavez (maurourielbasurto@gmail.com)
 * @brief Ejerciciop 1. Peliculas
 * @version 0.1
 * @date 2025-10-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <iostream>
#include <vector>

using namespace std;

class Pelicula
{
private:
    string titulo;
    int anio;
    int duracion;
    string clasificacion;
    string director;
    string autoresprincipales;
    string descripcion;

public:
    Pelicula() {}

    Pelicula(string titulo, int anio, int duracion, string clasificacion,
             string director, string autoresprincipales, string descripcion)
    {
        this->titulo = titulo;
        this->anio = anio;
        this->duracion = duracion;
        this->clasificacion = clasificacion;
        this->director = director;
        this->autoresprincipales = autoresprincipales;
        this->descripcion = descripcion;
    }

    string getTitulo() const { return titulo; }
    int getAnio() const { return anio; }
    int getDuracion() const { return duracion; }
    string getClasificacion() const { return clasificacion; }
    string getDirector() const { return director; }
    string getAutoresPrincipales() const { return autoresprincipales; }
    string getDescripcion() const { return descripcion; }

    void setTitulo(string titulo) { this->titulo = titulo; }
    void setAnio(int anio) { this->anio = anio; }
    void setDuracion(int duracion) { this->duracion = duracion; }
    void setClasificacion(string clasificacion) { this->clasificacion = clasificacion; }
    void setDirector(string director) { this->director = director; }
    void setAutoresprincipales(string autoresprincipales) { this->autoresprincipales = autoresprincipales; }
    void setDescripcion(string descripcion) { this->descripcion = descripcion; }

    void mostrarInfo() const
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Anio: " << anio << endl;
        cout << "Duracion: " << duracion << " min" << endl;
        cout << "Clasificacion: " << clasificacion << endl;
        cout << "Director: " << director << endl;
        cout << "Autores principales: " << autoresprincipales << endl;
        cout << "Descripcion: " << descripcion << endl;
    }
};

class Catalogo
{
private:
    vector<Pelicula> peliculas;

public:
    void agregarPelicula(const Pelicula& pelicula)
    {
        peliculas.push_back(pelicula);
    }

    const vector<Pelicula>& getPeliculas() const
    {
        return peliculas;
    }

    bool estaVacio() const
    {
        return peliculas.empty();
    }

    void mostrarCatalogo() const
    {
        if (peliculas.empty())
        {
            cout << "El catálogo está vacio." << endl;
            return;
        }

        cout << "=== Catalogo de Peliculas ===" << endl;
        for (const auto& p : peliculas)
        {
            p.mostrarInfo();
        }
    }
};

int main()
{
    Catalogo catalogo;

    Pelicula a("Cars", 2003, 120, "A", "Walt Disney", "Walt Disney", "Un carro que consigue amigos pobres.");
    Pelicula b("Velocipastor", 2000, 180, "C", "Bimbolovan", "Ghandhi", "Un pastor que desea ser velocirraptor.");

    catalogo.agregarPelicula(a);
    catalogo.agregarPelicula(b);

    catalogo.mostrarCatalogo();

    return 0;
}
