

 #ifndef _MUTEX_H_       // ① Si no está definido _MUTEX_H_
#define _MUTEX_H_       // ② Definirlo y continuar con el contenido

struct mutex{ //Tabla de proceso del mutex. 

int32 proceso; 
sid32 semaforo;

};

sid32 mutex_init(int proceso); //Definimos las funciones.
syscall mutex_lock(sid32 sem);
syscall mutex_unlock(sid32 sem);

#endif /* _MUTEX_H_ */  // ③ Fin del bloque condicional
