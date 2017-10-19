#include <stdlib.h>
#include <stdint.h>
#include <Python.h>
#include <segfault.h>


static PyMethodDef methods[] =
{
    {"do_something", do_something, METH_VARARGS, "do something!"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module =
{
    PyModuleDef_HEAD_INIT,
    "_segfault",
    NULL,
    -1,
    methods
};


PyMODINIT_FUNC PyInit__segfault(void)
{
    return PyModule_Create(&module);
}


PyObject *do_something(PyObject *self, PyObject *args)
{

    int size;
    int num;
    uint8_t *buf;
    double total = 0;

    if (!PyArg_ParseTuple(args, "ii", &size, &num))
    {
        return NULL;
    }

    if ((buf = malloc(size * sizeof(*buf))) == NULL)
    {
        PyErr_SetString(PyExc_MemoryError, "Failed to allocate buffer!");
        return NULL;
    }

    for (int i = 0; i < num; i++)
    {
        buf[i] = i;
        fprintf(stdout, "buf[%3d] = 0x%02x\n", i, buf[i]);
        total += buf[i];
    }

    free(buf);

    return PyFloat_FromDouble(total);
}
