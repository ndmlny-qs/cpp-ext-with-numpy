#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define PY_ARRAY_UNIQUE_SYMBOL trig_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"

#include "cosine.cpp"
#include "numpy_cosine.cpp"

int has_numpy;

static char trig_docstring[] = "Trigonometric functions in C++.";
// static char cosine_docstring[] = "Compute the cosine of the given value using C++.";
// static char np_cosine_docstring[] = "Compute the cose of the given value using NumPy."

static PyMethodDef methods[] = {
  // {<python-method-name>, <c-method-name>, <method-input-types>, <method-docstring>}
  {"cosine", cosine, METH_VARARGS, NULL},
  {"np_cosine", np_cosine, METH_VARARGS, NULL},
  {NULL, NULL, 0, NULL} // sentinel
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "trig", // Name of module to import in Python.
  trig_docstring, // Module documentation.
  -1,
  methods
};

PyMODINIT_FUNC PyInit_trig(void) {

  import_array(); // Try to initialize NumPy, which should be installed during the build.
  if (PyErr_Occurred()) { // Check if NumPy is installed at runtime.
    return NULL;
  }

  return PyModule_Create(&module);
}
