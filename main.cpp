#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";

struct Paciente{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void Leer();
void Crear();
void Actualizar();
void Borrar();

int main() {
	Leer();
  	Crear();
  	Borrar();
	Actualizar();
  	
	system("pause");
    return 0;
}
void Leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Paciente paciente;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&paciente,sizeof(Paciente),1,archivo);
	cout<<"___________________________________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"   Nombres  "<<"|"<<"   Apellidos   "<<"|"<<" Telefono"<<endl;
	do{
		cout<<id<<"|"<<paciente.codigo<<"|"<<paciente.nombres<<"|"<<paciente.apellidos<<"|"<<paciente.telefono<<endl;
		fread(&paciente,sizeof(Paciente),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Paciente paciente;
	do{
		fflush(stdin);
		cout<<"Ingrese Codigo:";
		cin>>paciente.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres:";
		cin.getline(paciente.nombres,50);
		
		cout<<"Ingrese Apellidos:";
		cin.getline(paciente.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>paciente.telefono;
		
		fwrite(&paciente,sizeof(Paciente),1,archivo);
		cout<<"Desea ingresar otro paciente(s/n):";
		cin>>res;
	}while(res=='s' || res=='S');
	fclose(archivo);
	Leer();
}
void Actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	Paciente paciente;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Paciente),SEEK_SET);
		cout<<"Ingrese Codigo:";
		cin>>paciente.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres:";
		cin.getline(paciente.nombres,50);
		
		cout<<"Ingrese Apellidos:";
		cin.getline(paciente.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>paciente.telefono;
		
		fwrite(&paciente,sizeof(Paciente),1,archivo);
	
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.csv";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Paciente paciente;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&paciente,sizeof(Paciente),1,archivo)){
		if (id_n !=id ){
			fwrite(&paciente,sizeof(Paciente),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&paciente,sizeof(Paciente),1,archivo_temp)){
		fwrite(&paciente,sizeof(Paciente),1,archivo);
		
	}
		fclose(archivo);
	fclose(archivo_temp);
	Leer();
}
/*
 
 
 Otros ejemplos para busqueda por medio de codigo indice etc
 
 
 */
void buscar_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Paciente paciente;
	fread(&paciente,sizeof(Paciente),1,archivo);	
	do{
	   if(paciente.codigo == cod)	{
	   	cout<<"Codigo: "<<paciente.codigo<<endl;
	   	cout<<"Nombres: "<<paciente.nombres<<endl;
	   	cout<<"Apellidos: "<<paciente.apellidos<<endl;
	   	cout<<"Telefono: "<<paciente.telefono<<endl;
	   }
	   fread(&paciente,sizeof(Paciente),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}
/*void buscar_codigo(){
	
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Paciente paciente;
	
	fread ( &paciente, sizeof(Paciente), 1, archivo );
		
		do{
			
			if (paciente.codigo == cod){
			pos = indice;
			}
	
		fread ( &paciente, sizeof(Paciente), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Paciente), SEEK_SET );
    fread ( &paciente, sizeof( Paciente ), 1, archivo );
    	cout << "Codigo: " << paciente.codigo << endl;
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "Apellido: " << paciente.apellido << endl;
        cout << "Telefono: " << paciente.telefono << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}
*/

void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Paciente), SEEK_SET );
	
	Paciente paciente;
	
    fread ( &paciente, sizeof( Paciente ), 1, archivo );

    	cout << "Codigo: " << paciente.codigo << endl;
        cout << "Nombre: " << paciente.nombres<< endl;
        cout << "Apellido: " << paciente.apellidos << endl;
        cout << "Telefono: " << paciente.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}




