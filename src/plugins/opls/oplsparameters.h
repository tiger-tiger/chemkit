/******************************************************************************
**
** Copyright (C) 2009-2011 Kyle Lutz <kyle.r.lutz@gmail.com>
** All rights reserved.
**
** This file is a part of the chemkit project. For more information
** see <http://www.chemkit.org>.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**     documentation and/or other materials provided with the distribution.
**   * Neither the name of the chemkit project nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
******************************************************************************/

#ifndef OPLSPARAMETERS_H
#define OPLSPARAMETERS_H

#include <QtCore>

#include <chemkit/chemkit.h>
#include <chemkit/forcefieldatom.h>

struct OplsBondStrechParameters
{
    int typeA;
    int typeB;
    chemkit::Real kb;
    chemkit::Real r0;
};

struct OplsAngleBendParameters
{
    int typeA;
    int typeB;
    int typeC;
    chemkit::Real ka;
    chemkit::Real theta0;
};

struct OplsTorsionParameters
{
    int typeA;
    int typeB;
    int typeC;
    int typeD;
    chemkit::Real v1;
    chemkit::Real v2;
    chemkit::Real v3;
};

struct OplsVanDerWaalsParameters
{
    chemkit::Real sigma;
    chemkit::Real epsilon;
};

class OplsParameters
{
public:
    // construction and destruction
    OplsParameters(const QString &fileName);
    ~OplsParameters();

    // properties
    void setFileName(const QString &fileName);
    QString fileName() const;

    // parameters
    int atomClass(int type) const;
    QString atomName(int type) const;
    chemkit::Real partialCharge(int type) const;
    const OplsBondStrechParameters* bondStrechParameters(int a, int b) const;
    const OplsAngleBendParameters* angleBendParameters(int a, int b, int c) const;
    const OplsTorsionParameters* torsionParameters(int a, int b, int c, int d) const;
    const OplsVanDerWaalsParameters* vanDerWaalsParameters(int type) const;

private:
    bool read(const QString &fileName);

private:
    QString m_fileName;
    QVector<int> m_typeToClass;
    QVector<QString> m_typeToName;
    QVector<OplsBondStrechParameters> m_bondStrechParameters;
    QVector<OplsAngleBendParameters> m_angleBendParameters;
    QVector<OplsTorsionParameters> m_torsionParameters;
    QVector<OplsVanDerWaalsParameters> m_vanDerWaalsParameters;
    QVector<chemkit::Real> m_typeToCharge;
};

#endif // OPLSPARAMETERS_H
