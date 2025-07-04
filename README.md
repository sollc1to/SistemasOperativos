# Sistemas Operativos – Resumen de Prácticas en XINU y Linux

Este proyecto resume los conceptos y prácticas que desarrollé a lo largo de la materia Sistemas Operativos, utilizando tanto el sistema operativo educativo **XINU**
como herramientas de **Linux**.

---

## 🔧 XINU – Sistema Operativo Educativo

XINU (Experimental Integrated Networked Unix) es un sistema operativo simple y didáctico, ideal para comprender cómo funciona internamente un sistema operativo desde cero.

###  Temas abordados en XINU:

- **Procesos y planificación**  
  - Creación de procesos (`create`, `resume`, `sleep`)  
  - Prioridades 

- **Sincronización**  
  - Semáforos (`wait`, `signal`)  
  - Implementación de **mutex**  
  - Ejercicios clásicos: productor-consumidor, lectores-escritores, taxista-pasajero, etc.

- **Comunicación entre procesos**  
  - Envío de mensajes (`send`, `receive`)  
  - Ejercicios con `sendMsg` y `recvMsg` para comunicación directa


---

## 🐧 Linux – Programación de bajo nivel y llamadas al sistema

Además de XINU, trabajamos con programación en C sobre **Linux**, haciendo uso directo de **llamadas al sistema (syscalls)**.

###  Temas abordados en Linux:

- **Llamadas al sistema básicas**
  - `open`, `read`, `write`, `close`
  - Gestión de archivos con descriptores

- **Memoria compartida POSIX**
  - `shm_open`, `ftruncate`, `mmap`, `shm_unlink`
  - Uso de `shm_overview` para comprender el modelo
  - Creación de procesos que comparten memoria

- **Procesos y concurrencia**
  - Uso de `fork` y `wait`
  - Prácticas donde múltiples procesos acceden a memoria compartida de forma segura

- **Manejo de  permisos**
  - Gestión de permisos (`0666`, `O_CREAT`, etc.)


