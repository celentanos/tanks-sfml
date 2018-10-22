#ifndef TSINGLETON_H
#define TSINGLETON_H

#include <iostream>

template <class T> class TSingleton {
protected:
  static T *m_pSingleton; // Statisches Objekt

public:
  virtual ~TSingleton() {} // Destruktor

  inline static T *Get() {  // Aufgabe: Wenn nötig, statisches Objekt erzeugen
                            // und Zeiger darauf zurückgeben
    if (!m_pSingleton)      // Existiert schon eine Instanz?
      m_pSingleton = new T; // Nein, dann neue Instanz erzeugen
    return (m_pSingleton);  // Zeiger auf die Instanz zurückgeben
  }

  static void Del() {        // Statisches Objekt freigeben
    if (m_pSingleton) {      // Gab es eine Instanz?
      delete (m_pSingleton); // Ja, dann freigeben
      m_pSingleton = NULL;   // und Zeiger auf NULL setzen
    }
  }
};

// Die statische Variable erzeugen
template <class T> T *TSingleton<T>::m_pSingleton = 0;

#endif // TSINGLETON_H
