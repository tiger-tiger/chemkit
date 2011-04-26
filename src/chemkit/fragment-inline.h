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

#ifndef CHEMKIT_FRAGMENT_INLINE_H
#define CHEMKIT_FRAGMENT_INLINE_H

#include "fragment.h"

#include "atom.h"

namespace chemkit {

// --- Properties ---------------------------------------------------------- //
/// Returns the number of atoms in the fragment.
inline int Fragment::size() const
{
    return atomCount();
}

/// Returns the molecule the fragment is a part of.
inline Molecule* Fragment::molecule() const
{
    return m_atoms[0]->molecule();
}

// --- Structure ----------------------------------------------------------- //
/// Returns the atom at \p index in the fragment.
inline Atom* Fragment::atom(int index) const
{
    return m_atoms[index];
}

/// Returns a list of all the atoms in the fragment.
inline std::vector<Atom *> Fragment::atoms() const
{
    return m_atoms;
}

/// Returns the number of atoms in the fragment.
inline int Fragment::atomCount() const
{
    return m_atoms.size();
}

/// Returns \c true if the fragment contains the atom.
inline bool Fragment::contains(const Atom *atom) const
{
    return atom->fragment() == this;
}

} // end chemkit namespace

#endif // CHEMKIT_FRAGMENT_INLINE_H
