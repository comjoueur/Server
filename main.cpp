#include<iostream>
#include<winsock2.h>
#include<winsock.h>
 //Winsock Library
using namespace std;
class Sockets{
    public:
    SOCKET s;
    bool revision_socket(){
        if(s==INVALID_SOCKET){
            cout<<"No se pudo crear el socket"<<endl;
            return 1;
        }
        cout<<"Socket creado..."<<endl;
        return 0;
    }
    sockets(){
        cout<<"Creando Socket..."<<endl;
        s = socket(AF_INET , SOCK_STREAM , 0 );
    }
};
class Servidor{
    public:
    sockaddr_in servidor;
    Servidor(int puerta=80){
        servidor.sin_addr.s_addr=inet_addr("74.125.235.20");
        servidor.sin_family=AF_INET;
        servidor.sin_port=htons(puerta);
    }
    bool conexion(Sockets s){
        if(connect(s.s , (struct sockaddr *)&servidor , sizeof(servidor)) < 0){
            cout<<"error de conexion"<<endl;
            return 1;
        }
        cout<<"Conectado"<<endl;
        return 0;
    }
};
bool revision_Winsock(){
    WSADATA wsa;
    cout<<"Iniciando Winsock..."<<endl;
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
        //revisa si funciona winsock con respecto a la funcion y la informacion proveida
        cout<<"Falla. Error de codigo: "<<WSAGetLastError()<<endl;
        return 1;
    }
    cout<<"Iniciado..."<<endl;
    return 0;
}
int main()
{
    if(revision_Winsock())return 0;
    Sockets s;
    if(s.revision_socket()) return 0;
    Servidor t;
    if(t.conexion(s))return 0;
}
