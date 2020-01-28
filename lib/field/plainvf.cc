#include "plainvf.h"

/**
 ********************************************************************************************************************************************
 * \brief   Constructor of the plainvf class
 *
 *          Three blitz arrays to store the data of the three component scalar fields are initialized.
 *          The name for the plain vector field as given by the user is also assigned.
 *
 * \param   gridData is a const reference to the global data contained in the grid class
 * \param   refV is a const reference to a sample vfield according to whose components the components of plainvf is resized
 ********************************************************************************************************************************************
 */
plainvf::plainvf(const grid &gridData, const vfield &refV): gridData(gridData) {
    Vx.resize(refV.Vx.fSize);
    Vx.reindexSelf(refV.Vx.flBound);

    mpiVxData = new mpidata(Vx, gridData.rankData);
    mpiVxData->createSubarrays(refV.Vx.fSize, refV.Vx.cuBound + 1, gridData.padWidths, refV.Vx.xStag, refV.Vx.yStag);

    Vy.resize(refV.Vy.fSize);
    Vy.reindexSelf(refV.Vy.flBound);

    mpiVyData = new mpidata(Vy, gridData.rankData);
    mpiVyData->createSubarrays(refV.Vy.fSize, refV.Vy.cuBound + 1, gridData.padWidths, refV.Vy.xStag, refV.Vy.yStag);

    Vz.resize(refV.Vz.fSize);
    Vz.reindexSelf(refV.Vz.flBound);

    mpiVzData = new mpidata(Vz, gridData.rankData);
    mpiVzData->createSubarrays(refV.Vz.fSize, refV.Vz.cuBound + 1, gridData.padWidths, refV.Vz.xStag, refV.Vz.yStag);
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to add a given plain vector field
 *
 *          The unary operator += adds a given plain vector field to the entire field stored as plainvf and returns
 *          a pointer to itself.
 *
 * \param   a is a reference to another plainvf to be deducted from the member fields
 *
 * \return  A pointer to itself is returned by the plain vector field class to which the operator belongs
 ********************************************************************************************************************************************
 */
plainvf& plainvf::operator += (plainvf &a) {
    Vx += a.Vx;
    Vy += a.Vy;
    Vz += a.Vz;

    return *this;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to subtract a given plain vector field
 *
 *          The unary operator -= subtracts a given plain vector field from the entire field stored as plainvf and returns
 *          a pointer to itself.
 *
 * \param   a is a reference to another plainvf to be deducted from the member fields
 *
 * \return  A pointer to itself is returned by the plain vector field class to which the operator belongs
 ********************************************************************************************************************************************
 */
plainvf& plainvf::operator -= (plainvf &a) {
    Vx -= a.Vx;
    Vy -= a.Vy;
    Vz -= a.Vz;

    return *this;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to add a given vector field
 *
 *          The unary operator += adds a given vector field to the entire field stored as plainvf and returns
 *          a pointer to itself.
 *
 * \param   a is a reference to another vfield to be deducted from the member fields
 *
 * \return  A pointer to itself is returned by the plain vector field class to which the operator belongs
 ********************************************************************************************************************************************
 */
plainvf& plainvf::operator += (vfield &a) {
    Vx += a.Vx.F;
    Vy += a.Vy.F;
    Vz += a.Vz.F;

    return *this;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to subtract a given vector field
 *
 *          The unary operator -= subtracts a given vector field from the entire field stored as plainvf and returns
 *          a pointer to itself.
 *
 * \param   a is a reference to another vfield to be deducted from the member fields
 *
 * \return  A pointer to itself is returned by the plain vector field class to which the operator belongs
 ********************************************************************************************************************************************
 */
plainvf& plainvf::operator -= (vfield &a) {
    Vx -= a.Vx.F;
    Vy -= a.Vy.F;
    Vz -= a.Vz.F;

    return *this;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to multiply a scalar value to the plain vector field
 *
 *          The unary operator *= multiplies a real value to all the fields (Vx, Vy and Vz) stored in plainvf and returns
 *          a pointer to itself.
 *
 * \param   a is a real number to be multiplied to the plain vector field
 *
 * \return  A pointer to itself is returned by the plain vector field class to which the operator belongs
 ********************************************************************************************************************************************
 */
plainvf& plainvf::operator *= (real a) {
    Vx *= a;
    Vy *= a;
    Vz *= a;

    return *this;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to assign another plain vector field to the plain vector field
 *
 *          The operator = assigns all the three scalar sub-fields of a plainvf to all the corresponding fields (Vx, Vy and Vz).
 *
 * \param   a is a plainvf to be assigned to the plain vector field
 ********************************************************************************************************************************************
 */
void plainvf::operator = (plainvf &a) {
    Vx = a.Vx;
    Vy = a.Vy;
    Vz = a.Vz;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to assign another vector field to the plain vector field
 *
 *          The operator = assigns all the three scalar sub-fields of a plainvf to all the corresponding fields (Vx, Vy and Vz).
 *
 * \param   a is a vfield to be assigned to the plain vector field
 ********************************************************************************************************************************************
 */
void plainvf::operator = (vfield &a) {
    Vx = a.Vx.F;
    Vy = a.Vy.F;
    Vz = a.Vz.F;
}

/**
 ********************************************************************************************************************************************
 * \brief   Overloaded operator to assign a scalar value to the plain vector field
 *
 *          The operator = assigns a real value to all the fields (Vx, Vy and Vz) stored in plainvf.
 *
 * \param   a is a real number to be assigned to the plain vector field
 ********************************************************************************************************************************************
 */
void plainvf::operator = (real a) {
    Vx = a;
    Vy = a;
    Vz = a;
}