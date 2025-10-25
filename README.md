# 🐴 Sistema de Gestión de Herrería Equina

Aplicación desarrollada como proyecto de **Programación II** para la gestión integral de clientes, caballos, trabajos realizados, materiales utilizados y recaudación en una herrería equina.

---

## 👥 Integrantes
- **Macarena Amores**  
- **Guillermo Caratini**  
- **Sebastián Cabeza**  
- **Jazmín Erásun**

---

## 🎯 Objetivo del sistema

El sistema tiene como objetivo principal **centralizar y automatizar** la información relacionada con la actividad de una herrería equina:

- Gestión de **clientes** con sus datos personales y de contacto.  
- Registro de **caballos** asociados a cada cliente, incluyendo datos como nombre, edad y raza.  
- Administración de **trabajos** realizados (herrado o desvasado), materiales empleados y costos.  
- Control de **stock de materiales** (herraduras, clavos, etc.).  
- **Agenda automática** que genera recordatorios de próximos servicios según el tipo de trabajo.  
- **Copia de seguridad** y **exportación de datos** en formato CSV.  

---

## 📋 Funcionalidades principales

### 🧾 Módulos del sistema
- **Clientes:** alta, baja, modificación y consultas.  
- **Caballos:** asociados a clientes, con historial de trabajos.  
- **Trabajos:** registro de tareas realizadas, fecha, tipo, materiales usados y costos.  
- **Materiales:** gestión de stock y consumos por período.  
- **Agenda:** programación automática de próximas visitas (30 o 40 días según el servicio).  

### 📤 Salidas del sistema
- **Listados:**
  - Clientes (ordenados por nombre o apellido)
  - Caballos (filtrado por cliente o ID)
  - Trabajos realizados en un período
  - Materiales en stock  

- **Consultas:**
  - Próximos trabajos (agenda)
  - Historial de un caballo específico
  - Materiales con stock
  - Clientes por DNI o nombre  

- **Informes:**
  - Recaudación mensual y anual
  - Recaudación por cliente
  - Materiales consumidos por período  
  - Exportación a **CSV** o **PDF**

---

## ⚙️ Configuración

El sistema permite:
1. **Realizar copias de seguridad** de todos los archivos.  
2. **Restaurar copias de seguridad**.  
3. **Exportar datos** en formato CSV para planillas de cálculo.

---

## 💾 Estructura del proyecto

├── src/
│ ├── main.cpp
│ ├── Agenda.h
│ ├── Archivos.h
│ ├── Caballo.h
│ ├── Cliente.h
│ ├── Material.h
│ ├── MaterialesUsados.h
│ ├── Trabajo.h
│ └── Usuario.h
├── bin/
├── obj/
├── gestion equina.cbp
└── README.md


## 🧠 Tecnologías utilizadas
- **Lenguaje:** C++  
- **Entorno:** Code::Blocks  
- **Gestión de versiones:** Git / GitHub  
- **Archivos:** binarios y CSV  
- **Exportación:** PDF / CSV  

---


