/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Python.h>
#include <stdio.h>

static PyObject *void_foo_void(PyObject *self, PyObject *args) {
    Py_RETURN_NONE;
}


static PyObject *int_foo_int(PyObject *self, PyObject *args) {
    int a_int;

    if (!PyArg_ParseTuple(args, "i", &a_int)) {
        return NULL;
    }

    return PyLong_FromLong(a_int + 1);
}

static PyObject *void_foo_int(PyObject *self, PyObject *args) {
    int a_int;

    if (!PyArg_ParseTuple(args, "i", &a_int)) {
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *void_foo_int_int(PyObject *self, PyObject *args) {
    int a_int, b_int;

    if (!PyArg_ParseTuple(args, "ii", &a_int, &b_int)) {
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *void_foo_int_int_int(PyObject *self, PyObject *args) {
    int a_int, b_int, c_int;

    if (!PyArg_ParseTuple(args, "iii", &a_int, &b_int, &c_int)) {
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *void_foo_int_int_int_int(PyObject *self, PyObject *args) {
    int a_int, b_int, c_int, d_int;

    if (!PyArg_ParseTuple(args, "iiii", &a_int, &b_int, &c_int, &d_int)) {
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyObject *void_foo_constchar(PyObject *self, PyObject *args) {
    const char *a;

    if (!PyArg_ParseTuple(args, "s", &a)) {
        return NULL;
    }

    Py_RETURN_NONE;
}

static PyMethodDef foo_methods[] = {
    {"void_foo_void",  void_foo_void, METH_NOARGS, "void foo(void)"},
    {"int_foo_int",  int_foo_int, METH_VARARGS, "int foo(int)"},
    {"void_foo_int",  void_foo_int, METH_VARARGS, "void foo(int)"},
    {"void_foo_int_int",  void_foo_int_int, METH_VARARGS, "void foo(int, int)"},
    {"void_foo_int_int_int",  void_foo_int_int_int, METH_VARARGS, "void foo(int, int, int)"},
    {"void_foo_int_int_int_int",  void_foo_int_int_int_int, METH_VARARGS, "void foo(int, int, int, int)"},
    {"void_foo_constchar",  void_foo_constchar, METH_VARARGS, "void foo(const char *)"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef foo_module =
{
    PyModuleDef_HEAD_INIT,
    "foo_ext", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    foo_methods
};


PyMODINIT_FUNC PyInit_foo_ext(void)
{
    return PyModule_Create(&foo_module);
}

