/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture                          *
*                (c) 2006-2018 INRIA, USTL, UJF, CNRS, MGH                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                           Plugin SoftRobots    v1.0                         *
*				                                              *
* This plugin is also distributed under the GNU LGPL (Lesser General          *
* Public License) license with the same conditions than SOFA.                 *
*                                                                             *
* Contributors: Defrost team  (INRIA, University of Lille, CNRS,              *
*               Ecole Centrale de Lille)                                      *
*                                                                             *
* Contact information: https://project.inria.fr/softrobot/contact/            *
*                                                                             *
******************************************************************************/
#ifndef SOFA_COMPONENT_ENGINE_CENTEROFMASS_H
#define SOFA_COMPONENT_ENGINE_CENTEROFMASS_H

#include <sofa/core/DataEngine.h>

#include <sofa/core/behavior/MechanicalState.h>
#include <sofa/core/behavior/Mass.h>

#include "../initSoftRobots.h"

namespace sofa
{

namespace component
{

namespace engine
{

/**
 * This class computes the volume of a given closed surfacic mesh.
 * Description can be found at:
 * https://project.inria.fr/softrobot/documentation/engine/CenterOfMass
 */
template <class DataTypes>
class SOFA_SOFTROBOTS_API CenterOfMass : public core::DataEngine
{
public:
    SOFA_CLASS(SOFA_TEMPLATE(CenterOfMass,DataTypes),core::DataEngine);

    typedef typename DataTypes::VecCoord VecCoord;

    typedef typename DataTypes::Coord  Coord;
    typedef typename Coord::value_type Real;

    typedef typename core::behavior::MechanicalState<DataTypes> MechanicalState;
    typedef typename core::behavior::Mass<DataTypes>            Mass;

public:

    virtual std::string getTemplateName() const
    {
        return templateName(this);
    }

    static std::string templateName(const CenterOfMass<DataTypes>* = nullptr)
    {
        return DataTypes::Name();
    }

    CenterOfMass();

    virtual ~CenterOfMass();


    ////////////////////////// Inherited from BaseObject ///////////////////
    virtual void init() override;
    virtual void reinit() override;
    virtual void draw(const core::visual::VisualParams* vparams) override;
    ////////////////////////////////////////////////////////////////////////


    ////////////////////////// Inherited from DDGNode /////////////////////
    virtual void update() override;
    virtual void handleEvent(core::objectmodel::Event *event) override;
    ///////////////////////////////////////////////////////////////////////

    Coord getCenterOfMass() {return d_centerOfMass.getValue();}

protected:

    MechanicalState* m_state;
    Mass* m_mass;

    Data<Coord>   d_centerOfMass;
    Data<bool>    d_visualization;
    Data<float>   d_visuSize;
    Data<defaulttype::Vec4f>   d_visuColor;

    void computeCenterOfMass();

};

// Declares template as extern to avoid the code generation of the template for
// each compilation unit. see: http://www.stroustrup.com/C++11FAQ.html#extern-templates
#ifdef SOFA_EXTERN_TEMPLATE
#ifdef SOFA_WITH_DOUBLE
extern template class SOFA_SOFTROBOTS_API CenterOfMass<sofa::defaulttype::Vec3dTypes>;
#endif

#ifdef SOFA_WITH_FLOAT
extern template class SOFA_SOFTROBOTS_API CenterOfMass<sofa::defaulttype::Vec3fTypes>;
#endif
#endif //SOFA_EXTERN_TEMPLATE

} // namespace engine

} // namespace component

} // namespace sofa

#endif
