#include <Python.h>


PyMODINIT_FUNC PyInit__memleak(void);
PyObject *allocate(PyObject *self, PyObject *args);
