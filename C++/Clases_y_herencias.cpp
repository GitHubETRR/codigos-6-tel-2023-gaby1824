#include <iostream>

using namespace std;

class componentes{
	private:
		string lugar, armario;
	public:
		void set_lugar(string);
		string get_lugar(void);
		void set_armario(string);
		string get_armario(void);
};

class Resistor : public componentes{
	private:
		float resistencia, potencia_disipada;
		Resistor* siguiente;
	public:
		void set_resistencia(float);
		float get_resistencia(void);
		void set_potencia_disipada(float);
		float get_potencia_disipada(void);
		void set_siguiente(Resistor*);
		Resistor* get_siguiente(void);
};

class Capacitor : public componentes{
	private:
		float capacitancia, voltaje;
		Capacitor *siguiente;
	public:
		void set_capacitancia(float);
		float get_capacitancia(void);
		void set_voltaje(float);
		float get_voltaje(void);
		void set_siguiente(Capacitor*);
		Capacitor* get_siguiente(void);
};

typedef Resistor* p_Resistor; //Redefino p_Resistor a Resistor*
typedef Capacitor* p_Capacitor;

void componentes::set_lugar(string _lugar){
	lugar = _lugar;
}

string componentes::get_lugar(void){
	return lugar;
}

void componentes::set_armario(string _armario){
	armario = _armario;
}

string componentes::get_armario(void){
	return armario;
}

void Resistor::set_resistencia(float _resistencia){
	if(_resistencia > 0) resistencia=_resistencia;
	else cout<<("No se puede asignar un valor de resistencia menor a 0");
}

float Resistor::get_resistencia(void){
	return resistencia;
}

void Resistor::set_potencia_disipada(float _potencia_disipada){
	if(_potencia_disipada > 0) potencia_disipada = _potencia_disipada;
	else cout<<("No se puede asignar un valor de potencia disipada menor a 0");
}

float Resistor::get_potencia_disipada(void){
	return potencia_disipada;
}

void Resistor::set_siguiente(Resistor* _siguiente){ 
	siguiente = _siguiente;
}

Resistor* Resistor::get_siguiente(void){
	return siguiente;
}

void Capacitor::set_capacitancia(float _capacitancia){
	if(_capacitancia > 0) capacitancia=_capacitancia;
	else cout<<("No se puede asignar un valor de capacitancia menor a 0");
}

float Capacitor::get_capacitancia(void){
	return capacitancia;
}

void Capacitor::set_voltaje(float _voltaje){
	if(_voltaje > 0) voltaje = _voltaje;
	else cout<<("No se puede asignar un valor de tension menor a 0");
}

float Capacitor::get_voltaje(void){
	return voltaje;
}

void Capacitor::set_siguiente(Capacitor* _siguiente){
	siguiente = _siguiente;
}

Capacitor* Capacitor::get_siguiente(void){
	return siguiente;
}

char menu_inicio (void);

void Crear_Resistor (p_Resistor *);
void cambiar_valor_r (p_Resistor);
void cambiar_ubicacion_r (p_Resistor);
void mostrar_resistores (p_Resistor);
void borrar_resistor (p_Resistor *);

void Crear_Capacitor (p_Capacitor *);
void cambiar_valor_c (p_Capacitor);
void cambiar_ubicacion_c (p_Capacitor);
void mostrar_capacitores (p_Capacitor);
void borrar_capacitor (p_Capacitor *);

int main(){
	p_Resistor Comienzo_R = NULL; //Creo un puntero que apunte a la clase pero arranque en NULL
	p_Capacitor Comienzo_C = NULL;
	int Eleccion;
	do{
		Eleccion = menu_inicio();
		switch (Eleccion){
			case 1:
				Crear_Resistor(&Comienzo_R);
				break;
			case 2:
				cambiar_valor_r(Comienzo_R);
				break;
			case 3:
				cambiar_ubicacion_r(Comienzo_R);
				break;
			case 4:
				mostrar_resistores(Comienzo_R);
				break;
			case 5:
				borrar_resistor(&Comienzo_R);
				break;
			case 6:
				Crear_Capacitor(&Comienzo_C);
				break;
			case 7:
				cambiar_valor_c(Comienzo_C);
				break;
			case 8:
				cambiar_ubicacion_c(Comienzo_C);
				break;
			case 9:
				mostrar_capacitores(Comienzo_C);
				break;
			case 10:
				borrar_capacitor(&Comienzo_C);
				break;
		}
	}while(true);
	return 0;
}

char menu_inicio (void){
	int Eleccion; 
	do{
		cout<<"MENU"<<endl;
		cout<<"Crear RESISTOR -> 1"<<endl;
		cout<<"\t- Cambiar valor -> 2"<<endl;
		cout<<"\t- Cambiar ubicacion -> 3"<<endl;
		cout<<"\t- Mostrar resistores -> 4"<<endl;
		cout<<"\t- Eliminar resistor -> 5"<<endl;
		cout<<"Crear CAPACITOR -> 6"<<endl;
		cout<<"\t- Cambiar valor -> 7 "<<endl; 
		cout<<"\t- Cambiar ubicacion -> 8"<<endl;
		cout<<"\t- Mostrar capacitores -> 9"<<endl;
		cout<<"\t- Eliminar capacitor -> 10"<<endl;
		cout<<"Ingrese su eleccion: ";
		cin>>Eleccion;
	}while(!((Eleccion >= 1) && (Eleccion <= 10)));
	return Eleccion;
}        

void Crear_Resistor (p_Resistor* Comienzo_R){ 
	string lugar, armario;
	float resistencia, potencia_disipada;
	p_Resistor Nuevo_Resistor = new Resistor; //apunta a la nueva dirección de memoria 
	cout<<("Ingrese el aula en la cual guardara la resistencia: ");
	cin>>lugar;
	cout<<("Ingrese el armario en el cual guardara la resistencia: ");
	cin>>armario;
	cout<<("Ingrese el valor de resistencia en ohms: ");
	cin>>resistencia;
	cout<<("Ingrese la potencia que disipa el resistor en watts: ");
	cin>>potencia_disipada;
	Nuevo_Resistor->set_lugar(lugar); 
	Nuevo_Resistor->set_armario(armario);
	Nuevo_Resistor->set_resistencia(resistencia);
	Nuevo_Resistor->set_potencia_disipada(potencia_disipada);
	Nuevo_Resistor->set_siguiente(*Comienzo_R);
	*Comienzo_R = Nuevo_Resistor;
}

void cambiar_valor_r (p_Resistor comienzo){
	p_Resistor auxiliar = comienzo;
	float resistencia, potencia;
	bool bandera = true;
	cout<<"Ingrese el valor de resistencia a buscar: ";
	cin>>resistencia;
	cout<<"Ingrese el valor de potencia a buscar: ";
	cin>>potencia;
	while (auxiliar != NULL){
		if ((resistencia == auxiliar->get_resistencia()) && (potencia == auxiliar->get_potencia_disipada())){
			cout<<"Ingrese el nuevo valor de resistencia: ";
			cin>>resistencia;
			cout<<"Ingrese el nuevo valor de potencia: ";
			cin>>potencia;
			auxiliar->set_resistencia(resistencia);
			auxiliar->set_potencia_disipada(potencia);
			bandera = false;
			break;
		}
		auxiliar = auxiliar->get_siguiente();
	}
	if (bandera) cout<<"No se encontro ningun resitor que cumpla con los datos ingresados" << endl;
}

void cambiar_ubicacion_r (p_Resistor comienzo){
	p_Resistor auxiliar = comienzo;
	float resistencia, potencia;
	string lugar, armario;
	bool bandera = true;
	cout<<"Ingrese el valor de resistencia a buscar: ";
	cin>>resistencia;
	cout<<"Ingrese el valor de potencia a buscar: ";
	cin>>potencia;
	while (auxiliar != NULL){
		if ((resistencia == auxiliar->get_resistencia()) && (potencia == auxiliar->get_potencia_disipada())){
			cout<<"Ingrese el nuevo lugar del resistor: ";
			cin>>lugar;
			cout<<"Ingrese el nuevo armario del resistor: ";
			cin>>armario;
			auxiliar->set_lugar(lugar);
			auxiliar->set_armario(armario);
			bandera = false;
			break;
		}
		auxiliar = auxiliar->get_siguiente();
	}
	if (bandera) cout<<"No se encontro ningun resitor que cumpla con los datos ingresados" << endl;
}

void mostrar_resistores (p_Resistor comienzo){
	p_Resistor auxiliar = comienzo;
	int contador = 1;
	cout << "Resitores creados:"<<endl;
	while(auxiliar != NULL){
		cout<<" Resistor Numero: "<<contador<<endl;
		cout<<"\t- Resistencia: "<<auxiliar->get_resistencia()<<endl;
		cout<<"\t- Potencia Disipada: "<<auxiliar->get_potencia_disipada()<<endl;
		cout<<"\t- Lugar: "<<auxiliar->get_lugar()<<endl;
		cout<<"\t- Armario: "<<auxiliar->get_armario()<<endl<<endl;
		auxiliar = auxiliar->get_siguiente();
		contador++;
	}
}

void borrar_resistor (p_Resistor* comienzo){
	p_Resistor ahora = *comienzo, anterior = NULL;
	float resistencia, potencia;
	cout<<"Ingrese el valor de resistencia a eliminar: ";
	cin>>resistencia;
	cout<<"Ingrese el valor de potencia a eliminar: ";
	cin>>potencia;
	while (ahora != NULL){
		if ((resistencia == ahora->get_resistencia()) && (potencia == ahora->get_potencia_disipada())){
			if (anterior != NULL) anterior->set_siguiente(ahora->get_siguiente());
			else *comienzo = ahora->get_siguiente();
			delete(ahora);
			cout<<"El resistor de "<<resistencia<<"ohm y "<<potencia<<"W se elmino"<<endl;
			break;
		}
		anterior = ahora;
		ahora = ahora->get_siguiente();
		cout<<"No se encontro un resistor que cumpla con los valores pedidos para eliminar"<<endl<<endl;
	}
}

void Crear_Capacitor (p_Capacitor* Comienzo_C){
	string lugar,armario;
	float capacitancia, voltaje;
	p_Capacitor Nuevo_Capacitor = new Capacitor;
	cout<<("Ingrese el aula en la cual guardara el capacitor: ")<<endl;
	cin>>lugar;
	cout<<("Ingrese el armario en el cual guardara el capacitor: ")<<endl;
	cin>>armario;
	cout<<("Ingrese el valor de la capacitancia en faradios: ")<<endl;
	cin>>capacitancia;
	cout<<("Ingrese la tensión que trabaja el capacitor: ")<<endl;
	cin>>voltaje;
	Nuevo_Capacitor->set_lugar(lugar);
	Nuevo_Capacitor->set_armario(armario);
	Nuevo_Capacitor->set_capacitancia(capacitancia);
	Nuevo_Capacitor->set_voltaje(voltaje);
	Nuevo_Capacitor->set_siguiente(*Comienzo_C);
	*Comienzo_C = Nuevo_Capacitor;
}

void cambiar_valor_c (p_Capacitor comienzo){
	p_Capacitor auxiliar = comienzo;
    float capacitancia, voltaje;
	bool bandera = true;
    cout<<"Ingrese el valor de capacitancia a buscar: ";
    cin>>capacitancia;
    cout<<"Ingrese el valor de tension a buscar: ";
    cin>>voltaje;
    while (auxiliar != NULL){
        if ((capacitancia == auxiliar->get_capacitancia()) && (voltaje == auxiliar->get_voltaje())){
            cout<<"Ingrese el nuevo valor de resistencia: ";
            cin>>capacitancia;
            cout<<"Ingrese el nuevo valor de potencia: ";
            cin>>voltaje;
            auxiliar->set_capacitancia(capacitancia);
            auxiliar->set_voltaje(voltaje);
			bandera = false;
            break;
        }
		auxiliar = auxiliar->get_siguiente();
    }
    if (bandera) cout<<"No se encontro ningun capacitor que cumpla con los datos ingresados"<<endl;
}

void cambiar_ubicacion_c (p_Capacitor comienzo){
	p_Capacitor auxiliar = comienzo;
	float capacitancia, voltaje;
	string lugar, armario;
	bool bandera = true;
	cout<<"Ingrese el valor de capacitancia a buscar: ";
	cin>>capacitancia;
	cout<<"Ingrese el valor de voltaje a buscar: ";
	cin>>voltaje;
	while (auxiliar != NULL){
		if ((capacitancia == auxiliar->get_capacitancia()) && (voltaje == auxiliar->get_voltaje())){
			cout<<"Ingrese el nuevo lugar del capacitor: ";
			cin>>lugar;
			cout<<"Ingrese el nuevo armario del capacitor: ";
			cin>>armario;
			auxiliar->set_lugar(lugar);
			auxiliar->set_armario(armario);
			bandera = false;
			break;
		}
		auxiliar = auxiliar->get_siguiente();
	}
	if (bandera) cout<<"No se encontro ningun capacitor que cumpla con los datos ingresados"<<endl;
}

void mostrar_capacitores (p_Capacitor comienzo){
	p_Capacitor auxiliar = comienzo;
	int contador = 1;
	cout<<"Resitores creados:"<<endl;
	while(auxiliar != NULL){
		cout<<"Capacitor Numero: "<<contador<<endl;
		cout<<"Capacitancia: "<<auxiliar->get_capacitancia()<<endl;
		cout<<"Voltaje: "<<auxiliar->get_voltaje() << endl;
		cout<<"Lugar: "<<auxiliar->get_lugar()<<endl;
		cout<<"Armario: "<<auxiliar->get_armario()<<endl<<endl;
		auxiliar = auxiliar->get_siguiente();
		contador++;
	}
}

void borrar_capacitor (p_Capacitor* comienzo){
	p_Capacitor ahora = *comienzo, anterior = NULL;
	float capacitancia, voltaje;
	cout<<"Ingrese el valor de resistencia a buscar: ";
	cin>>capacitancia;
	cout<<"Ingrese el valor de potencia a buscar: ";
	cin>>voltaje;
	while (ahora != NULL){
		if ((capacitancia == ahora->get_capacitancia()) && (voltaje == ahora->get_voltaje())){
			if (anterior != NULL) anterior->set_siguiente(ahora->get_siguiente());
			else *comienzo = ahora->get_siguiente();
			delete(ahora);
			cout<<"El capacitor de "<<capacitancia<<"faradios y "<<voltaje<<"V se elmino"<<endl;
			break;
		}
		anterior = ahora;
		ahora = ahora->get_siguiente();
	}
}
