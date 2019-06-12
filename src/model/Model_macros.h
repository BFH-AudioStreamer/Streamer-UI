/**
 *******************************************************************************
 * @addtogroup Streamer-UI
 * @{
 * @addtogroup model
 * @{
 * @defgroup ModelMacros
 * @{
 * @brief Macros to ease the use of model classes
 *
 * @authors Stefan Lüthi
 *******************************************************************************
 * Copyright (C) 2019 Audio-Streamer Project Group
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *******************************************************************************
 */
#pragma once

/** @brief Simplify Q_PROPERTY() definitions by creating getters, setters and slots
 * automatically */
#define SIMPLE_Q_PROPERTY(TYPE, NAME) \
        Q_PROPERTY(TYPE NAME READ NAME WRITE set_##NAME NOTIFY NAME##_changed) \
    public: \
        TYPE NAME() const { return _##NAME; } \
        void set_##NAME(TYPE &value) { \
            if (_##NAME != value) { \
                _##NAME = value; \
                emit NAME##_changed(); \
            } \
        } \
        Q_SIGNAL void NAME##_changed(); \
    private: \
        TYPE _##NAME;
