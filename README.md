# 🍝 Philosophers - Dining Philosophers Problem

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Type](https://img.shields.io/badge/Concurrency-Threads-red.svg)
![Style](https://img.shields.io/badge/School-42-black.svg)

Una solución al clásico problema de sincronización de Dijkstra. Este proyecto demuestra el dominio de la programación multi-hilo y la gestión de recursos compartidos.

---

## 🎯 Retos Técnicos Superados

* **Multithreading:** Gestión de hilos individuales para cada filósofo utilizando la librería `pthread`.
* **Sincronización:** Uso de **Mutexes** para evitar condiciones de carrera (*race conditions*) y asegurar que los recursos (tenedores) se utilicen de forma atómica.
* **Optimización de Recursos:** Implementación de una lógica de monitorización para detectar muertes de hilos en tiempo real sin sobrecargar la CPU.
* **Prevención de Deadlocks:** Algoritmo diseñado para evitar el interbloqueo y la inanición (*starvation*).

---

## 🛠️ Tecnologías Clave

| Concepto | Herramienta |
| :--- | :--- |
| **Hilos** | `pthread_create`, `pthread_join` |
| **Exclusión Mutua** | `pthread_mutex_init`, `pthread_mutex_lock` |
| **Análisis de Memoria** | Valgrind / Helgrind / Address Sanitizer |
| **Tiempo** | `gettimeofday` para cronometría de alta precisión |

---

## 🔍 Estructura del Código

1.  **Parsing:** Validación de argumentos y configuración de la simulación.
2.  **Initialization:** Asignación de memoria y creación de mutexes para cada recurso compartido.
3.  **Simulation:** Ciclo de vida del hilo (Comer ➔ Dormir ➔ Pensar).
4.  **Monitoring:** Hilo de control que supervisa constantemente los tiempos de vida para finalizar la simulación si un filósofo muere.
5.  **Cleanup:** Liberación rigurosa de memoria y destrucción de mutexes.

---

## 👤 Contacto
**Emilio** - [LinkedIn]([https://linkedin.com/in/tu-perfil](https://www.linkedin.com/in/emilio-garcía-burgos-85a3a6334/))

---
> Proyecto desarrollado bajo los estándares de **42**, garantizando una gestión de memoria perfecta (0 leaks) y ausencia de *data races*.
