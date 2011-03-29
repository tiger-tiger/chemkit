#ifndef CHEMKIT_ATOMTYPER_H
#define CHEMKIT_ATOMTYPER_H

#include "chemkit.h"

#include <string>

#include <QtCore>

namespace chemkit {

class Atom;
class Molecule;
class AtomTyperPrivate;

class CHEMKIT_EXPORT AtomTyper
{
    public:
        // typedefs
        typedef AtomTyper* (*CreateFunction)();

        // construction and destruction
        virtual ~AtomTyper();

        // properties
        std::string name() const;
        void setMolecule(const Molecule *molecule);
        const Molecule* molecule() const;

        // types
        virtual QVariant type(int index) const;
        virtual QVariant type(const Atom *atom) const;
        virtual int typeNumber(int index) const;
        virtual int typeNumber(const Atom *atom) const;
        virtual std::string typeString(int index) const;
        virtual std::string typeString(const Atom *atom) const;

        // static methods
        static AtomTyper* create(const std::string &name);
        static std::vector<std::string> typers();

    protected:
        AtomTyper(const std::string &name);
        virtual void assignTypes(const Molecule *molecule);

    private:
        AtomTyperPrivate* const d;
};

} // end chemkit namespace

#endif // CHEMKIT_ATOMTYPER_H
