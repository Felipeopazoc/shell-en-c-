#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command1[] = "Salir";
char command2[] = "crearArchivo";
char command3[] = "mostrarContenido";
char command4[] = "listarArchivos";
char command5[] = "LimpiarPantalla";
char command6[] = "Manual";
char command7[] = "VerRuta";
FILE *fd;
FILE *archivo;


int main(){    
    char cadena[40];
    system("clear");
    printf("--------Bienvenido a mi shell ---------\n");
    printf("Para ver el listado de comandos disponibles ingrese 'Manual' en la shell\n\n");
    while (strcmp(cadena,command1)!=0){
            printf("<? ");
            scanf("%s",cadena);
            if( strcmp(cadena,command7)==0 || strcmp(cadena,command6)==0 ||strcmp(cadena,command1)==0 || strcmp(cadena,command2)==0 || strcmp(cadena,command3)==0 ||  strcmp(cadena,command5)==0 || strcmp(cadena,command4)==0){
                fflush(stdin);
                if(strcmp(cadena,command2)==0){
                    char nombreArchivo[40];
                    char direccion [] = "/home/felipe/Escritorio/Sistemas Operativos/";
                    fflush(stdin);
                    printf("Este comando creará un archivo .txt!, Ojo con la ruta del codigo fuente\n");
                    printf("Ingrese el nombre que tendra el archivo: ");
                    scanf("%s",nombreArchivo);
                    char direccionfinal[150];
                    strcpy(direccionfinal,direccion);
                    strcat(direccionfinal,nombreArchivo);
                    strcat(direccionfinal,".txt");
                    fd = fopen(direccionfinal,"w");
                    if(fd == NULL){
                        printf("\nError en la creacion del archivo, posiblemente la direccion del archivo es incorrecta\n");
                    }else{
                        printf("Se creo el archivo correctamente\n");
                    }

                }else if(strcmp(cadena,command3)==0){
                    fflush(stdin);
                    char direccion [] = "/home/felipe/Escritorio/Sistemas Operativos/";
                    char direccionfinal[150];
                    char nombreArchivo[40];
                    printf("Ingrese el nombre de archivo: ");
                    scanf("%s",nombreArchivo);
                    int c;
                    strcpy(direccionfinal,direccion);
                    strcat(direccionfinal,nombreArchivo);
                    strcat(direccionfinal,".txt");
                    archivo = fopen(direccionfinal,"rt");
                    if(archivo==NULL){
                        printf("Archivo no encontrado!\n");
                        
                    }else{
                        while((c=fgetc(archivo))!= EOF){
                            if(c=='\n'){
                                printf("\n");
                            }else{
                                putchar(c);
                            }
                        }
                        printf("\n");
                    }
                    fclose(archivo);
                }else if(strcmp(cadena,command4)==0){
                    system("ls");
                }else if(strcmp(cadena,command5)==0){
                    system("clear");
                }else if(strcmp(cadena,command6)==0){
                    printf("\n***********Manual de shell************\n\n");
                    printf("Salir = Salir de la shell\n");
                    printf("crearArchivo = Sirve para crear un archivo txt\n");
                    printf("mostrarTexto = Mostrar contenido del archivo txt\n");
                    printf("VerRuta = Muestra el directorio en el que estamos\n");
                    printf("listarArchivos = Muestra los archivos que hay disponibles\n");
                    printf("Limpiar = Limpia la consola\n");
                    printf("\n");
                }else if(strcmp(cadena,command7)==0){
                    system("pwd");
                }
            }else{
                printf("Error! comando invalido!\n");
            }
        }

    return 0;
}

