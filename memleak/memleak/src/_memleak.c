#include <stdlib.h>
#include <stdint.h>
#include <Python.h>
#include <memleak.h>


static PyMethodDef methods[] =
{
    {"allocate", allocate, METH_VARARGS, "allocate a buffer"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module =
{
    PyModuleDef_HEAD_INIT,
    "_memleak",
    NULL,
    -1,
    methods
};


PyMODINIT_FUNC PyInit__memleak(void)
{
    return PyModule_Create(&module);
}


PyObject *allocate(PyObject *self, PyObject *args)
{

    int size;
    uint8_t *buf;

    if (!PyArg_ParseTuple(args, "i", &size))
    {
        return NULL;
    }

    if ((buf = malloc(size * sizeof(*buf))) == NULL)
    {
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate buffer!");
        return NULL;
    }

    Py_RETURN_NONE;
}
