#define MAX_PRODUCTOS 150
#define MAX_NOMBRE 100
void agregarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *n_productos);
void listarProducto(const char nombres[][MAX_NOMBRE], const int cantidades[], const float precios[], int n_productos);
void editarPrecio(char nombres[][MAX_NOMBRE], float precios[], int n_productos);
void editarCantidad(char nombres[][MAX_NOMBRE], int cantidades[], int n_productos);
void eliminarProducto(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int *n_productos);
void desplazarProductos(char nombres[][MAX_NOMBRE], int cantidades[], float precios[], int indice, int n_productos);
int buscarProductoPorNombre(const char nombres[][MAX_NOMBRE], int n_productos, const char *nombre);
void ingresarCadenas(char *mensaje, char nombres[][MAX_NOMBRE], int cantidad);