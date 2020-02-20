#include <Python.h>

/**
* Extern library CUDA_DLL function
*/
extern void addTwoNumbers(int *a,int  *b,int *c);

static PyObject* add(PyObject* self, PyObject* args) {

    int* a, * b, * c;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    c = 0;
    addTwoNumbers(&a, &b, &c);
    int result = c;
    return Py_BuildValue("i", result);
}

/*
 * List of functions to add to CUDAModule in exec_CUDAModule().
 */
static PyMethodDef CUDAModule_functions[] = {
    { "add", (PyCFunction)add, METH_VARARGS, "add two numbers"},
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize CUDAModule. May be called multiple times, so avoid
 * using static state.
 */
int exec_CUDAModule(PyObject *module) {
    PyModule_AddFunctions(module, CUDAModule_functions);
    PyModule_AddStringConstant(module, "__author__", "Marcin Grzegorz Kaspryk");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2020);
    return 0; /* success */
}

/*
 * Documentation for CUDAModule.
 */
PyDoc_STRVAR(CUDAModule_doc, "The CUDAModule module");

static PyModuleDef_Slot CUDAModule_slots[] = {
    { Py_mod_exec, exec_CUDAModule },
    { 0, NULL }
};

static PyModuleDef CUDAModule_def = {
    PyModuleDef_HEAD_INIT,
    "CUDAModule",
    CUDAModule_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    CUDAModule_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_CUDAModule() {
    return PyModuleDef_Init(&CUDAModule_def);
}