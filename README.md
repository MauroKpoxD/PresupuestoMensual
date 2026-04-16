# Presupuesto Mensual

Un programa en C++ para llevar el control de tus ingresos y gastos directamente desde la consola.  
Ideal para aprender, para usar en casa o como base para algo más grande (¿una API REST?).

---

## Características

- Ingresar dinero (registra la fecha y hora automáticamente).
- Sacar dinero (gastos).
- Ver el balance actual (ingresos - gastos).
- Ver el historial completo de movimientos.
- Datos guardados en un archivo (`base_de_datos.money`).

> Próximamente: mostrar datos en forma de matriz, IDs para cada movimiento, exportar a CSV...

---

## Que necesitas

- Un compilador de C++ (recomendamos g++)
- Terminal / consola
- Ganas de no perder la cuenta de la plata

---

## Como compilar y ejecutar

### 1. Clonar o descargar el proyecto

```bash
git clone https://github.com/MauroKpoxD/PresupuestoMensual
cd PresupuestoMensual
```

### 2. Compilar con g++

```bash
g++ -std=c++11 -o presupuesto main.cpp
```

> Si queres guardar el ejecutable dentro de una carpeta `output`:
> ```bash
> mkdir output
> g++ -std=c++11 -o output/presupuesto main.cpp
> ```

### 3. Ejecutar

- En Linux / Mac:
  ```bash
  ./presupuesto
  ```
- En Windows (con MinGW):
  ```bash
  presupuesto.exe
  ```
  Si usaste la carpeta `output`:
  ```bash
  output\presupuesto.exe
  ```

---

## Firmar el ejecutable (opcional)

Para evitar que Windows bloquee el programa, podes firmarlo digitalmente con tu propio certificado.
Esto pasa porque modificas archivos con un programa sin firmar y por nuevas restricciones de seguridad.
Igualmente podes confiar que no es un virus porque tenes el codigo fuente en tus manos y la certeza
de que no hay nada ofuscado o cosas raras.

### Pasos rapidos

1. **Crear un certificado autofirmado** (PowerShell como Administrador):
   ```powershell
   New-SelfSignedCertificate -Type CodeSigningCert -Subject "CN=TuNombre" -CertStoreLocation Cert:\CurrentUser\My\
   ```

2. **Obtener la huella digital** del certificado recien creado:
   ```powershell
   Get-ChildItem Cert:\CurrentUser\My\ | Where-Object { $_.Subject -like "*TuNombre*" }
   ```
   Copias el valor de `Thumbprint` (una cadena como `EB7874BA316F7562620C2610FE4F06F09B868C8D`).

3. **Firmar el .exe** con `signtool` (reemplaza `[HUELLA]` por la huella que copiaste):
   ```bash
   signtool sign /fd SHA256 /td SHA256 /tr http://timestamp.digicert.com /sha1 [HUELLA] main.exe
   ```

   Ejemplo real:
   ```bash
   signtool sign /fd SHA256 /td SHA256 /tr http://timestamp.digicert.com /sha1 EB7874BA316F7562620C2610FE4F06F09B868C8D main.exe
   ```

> La herramienta `signtool` esta incluida en el Windows SDK o en Visual Studio. Si no la tenes, podes usar el "Developer PowerShell" que viene con Visual Studio.

---

## Como se usa

Al ejecutar el programa vas a ver un menu como este:

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

Solo tenes que escribir el numero de la opcion y seguir las instrucciones en pantalla.

### Ejemplo de historial guardado

```
+ 1000 2026-04-15 22:45:30
- 250 2026-04-15 23:10:12
+ 500 2026-04-16 09:20:45
```

---

## Estructura del proyecto

```
PresupuestoMensual/
├── output/                # Carpeta donde se guardan los ejecutables
├── main.cpp               # Codigo fuente
├── base_de_datos.money    # Se genera automaticamente (historial)
└── README.md              # Este archivo
```

---

## Estado del proyecto

Beta funcional – las operaciones basicas andan bien.  
Faltan algunas validaciones (por ejemplo, evitar numeros negativos, control de saldo insuficiente, etc.), pero es totalmente usable.

> Esto probablemente termine con solo esta beta.

---

## Queres colaborar

El proyecto es abierto. Podes:
- Probar el programa y reportar errores.
- Sugerir nuevas opciones (editar movimientos, graficos en consola, etc.).
- Pasar el codigo a algo mas lindo (API REST, base de datos SQLite...).

---

## Licencia

Ver el archivo LICENCE.md

---

*Si te sirvio, regalale una estrellita al repo.*