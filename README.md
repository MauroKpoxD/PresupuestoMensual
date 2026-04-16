# Presupuesto Mensual

Un programa en **C++** para llevar el control de tus ingresos y gastos directamente desde la consola.  
*Ideal para aprender, para usar en casa o como base para algo más grande (¿una API REST?)*

---

## Características

- Ingresar dinero (registra la fecha y hora automáticamente).
- Sacar dinero (gastos).
- Ver el **balance actual** (ingresos - gastos).
- Ver el **historial completo** de movimientos.
- Datos guardados en un archivo (`base_de_datos.money`).

> *Próximamente: mostrar datos en forma de matriz, IDs para cada movimiento, exportar a CSV...*

---

## ¿Qué necesitas?

- Un compilador de C++ (recomendamos **g++**)
- Terminal / consola
- Ganas de no perder la cuenta de la plata

---

## Cómo compilar y ejecutar

### 1. Clonar o descargar el proyecto

```bash
git clone https://github.com/MauroKpoxD/PresupuestoMensual
cd PresupuestoMensual
```

### 2. Compilar con g++

```bash
g++ -std=c++11 -o presupuesto main.cpp
```

> Si querés guardar el ejecutable dentro de una carpeta `output`:
> ```bash
> mkdir output
> g++ -std=c++11 -o output/presupuesto main.cpp
> ```

### 3. Ejecutar

- En **Linux / Mac**:
  ```bash
  ./presupuesto
  ```
- En **Windows** (con MinGW):
  ```bash
  presupuesto.exe
  ```
  Si usaste la carpeta `output`:
  ```bash
  output\presupuesto.exe
  ```

---

## 🎮 Cómo se usa

Al ejecutar el programa vas a ver un menú como este:

```
<------------------------------------------------->
|  Elije una opcion:                               |
|  1. Ingresar dinero                              |
|  2. Sacar dinero                                 |
|  3. Mostrar total (balance)                      |
|  4. Mostrar historial                            |
|  5. Salir                                        |
<------------------------------------------------->
```

Solo tenés que escribir el número de la opción y seguir las instrucciones en pantalla.

### Ejemplo de historial guardado

```
+ 1000 2026-04-15 22:45:30
- 250 2026-04-15 23:10:12
+ 500 2026-04-16 09:20:45
```

---

## 📁 Estructura del proyecto

```
PresupuestoMensual/
├── output/                # Todos los .exe
├── main.cpp               # Código fuente
├── base_de_datos.money    # Se genera automáticamente (historial)
└── README.md              # Este archivo
```

---

## Estado del proyecto

**Beta funcional** – las operaciones básicas andan bien.  
Faltan algunas validaciones (por ejemplo, evitar números negativos, control de saldo insuficiente, etc.), pero es totalmente usable.

> *Esto probablemente termine con solo esta beta.*

---

## ¿Querés colaborar?

¡El proyecto es abierto! Podés:
- Probar el programa y reportar errores.
- Sugerir nuevas opciones (editar movimientos, gráficos en consola, etc.).
- Pasar el código a algo más lindo (API REST, base de datos SQLite...).

---

## 📄 Licencia

LICENCE.md

---

*Si te sirvió, regalale una estrellita al repo.* ⭐
```