#include <stdio.h>
#define TAM 5

char *productos[TAM] = {"MiniAlbum","Lighstick","Playera","Peluche","Poster"};
int cantidad[TAM] = {15,5,20,30,50};
float precio[TAM] = {670,1300,1050,480,20};
int carrito[TAM] = {0,0,0,0,0};

void menu();
void elemtienda();
void elemcarrito();
void agregar();

int main(){
	printf("Bienvenidos a TwicexOnce shop");
	menu();
	return 0;
}

void menu(){
int opc=0;	
	printf("\n\nMenu principal");
	printf("\n\n1. Mostrar elementos de la tienda");
	printf("\n2. Mostrar elementos del carrito");
	printf("\n3. Agregar elementos al carrito");
	printf("\n4. Eliminar elementos del carrito");
	printf("\n5. Salir");
	printf("\nElija una opcion:");
	scanf("%i",&opc);
	switch(opc){
		case 1: elemtienda(); break;
		case 2: elemcarrito(); break;
		case 3: agregar(); break;
		case 4: eliminar(); break;
		case 5: printf("\n\n¡One in million! gracias vuelva pronto"); break;
		default: printf("Opcion no valida"); break;
	}	
}

void elemtienda(){
	int cont;
	printf("Los elementos de la tienda son :\n");
	for(cont=0;cont<TAM;cont++){
		printf("%d %s %i \n", cont+1, productos[cont], cantidad[cont]);
	}
}

void agregar(){
	elemtienda();
	int op, cant;
	printf("\n\nIngrese el producto que desea adquirir :");
	if(scanf("%d",&op) == 1){
		printf("\nIngrese la cantidad que desea adquirir :");
		if(scanf("%d",&cant) == 1){
			if(cant < cantidad[op-1]){
				carrito[op-1] += cant;
				cantidad[op-1] -= cant;			
				}
			else{
				printf("\n\nNo existe cantidad en stock");
			}
		}
		else{
			printf("\nDebe ingresar un numero");
		}
	}
	else{
		printf("\nDebe ingresar un numero");
	}
	elemcarrito();
}

void elemcarrito(){
	float compra = 0;
	int cont = 0;
	printf("No.\tProducto\tCantidad\tPrecio_pieza\tPrecio_total\n");
	for(cont=0;cont<TAM;cont++){
		if(carrito[cont]>0){
			printf("%d\t%s\t%d\t\t%f\t%f\n",cont+1,productos[cont],carrito[cont],precio[cont], carrito[cont]*precio[cont]);
			compra += carrito[cont]*precio[cont];
		}
	}
	printf("\nTotal a pagar: %f\n", compra);
	elemtienda();
	menu();
}

void eliminar(){
	int op, cant;
	printf("\nIngrese el numero del articulo que desea eliminar:");
	if(scanf("%d",&op) == 1){
		if(carrito[op-1]>0){
			printf("\nIngrese la cantidad que desea eliminar");
			if(scanf("%d", &cant) == 1){
				if(cant < cantidad[op-1]){
					carrito[op-1] -= cant;
					cantidad[op-1] += cant;
				}
				else{
					printf("No existe tal cantidad en el carrito");
				}
			}
			else{
				printf("No exite el articulo en el carrito");
			}
		}
		else{
			printf("Debes ingresar un numero");
		}
	}
	else{
		printf("Debes ingresar un numero");
	}	
	elemcarrito();
}
