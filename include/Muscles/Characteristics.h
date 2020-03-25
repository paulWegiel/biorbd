#ifndef BIORBD_MUSCLES_CHARACTERISTICS_H
#define BIORBD_MUSCLES_CHARACTERISTICS_H

#include <memory>
#include <cstddef>
#include "biorbdConfig.h"
#include "Utils/Scalar.h"

namespace biorbd {
namespace  muscles {
class State;
class FatigueParameters;
///
/// \brief Class Holds that muscle characteristics
///
class BIORBD_API Characteristics
{
public:
    ///
    /// \brief Construct characteristics
    ///
    Characteristics();

    ///
    /// \brief Construct characteristics from other characteristics
    /// \param other The other characteristics
    ///
    Characteristics(
            const biorbd::muscles::Characteristics& other);

    ///
    /// \brief Construct characteristics
    /// \param optLength Optimal length (where maximal force occurs)
    /// \param fmax The maximal isometric force at optimal length
    /// \param PCSA Physiological cross-sectional area of the muscle
    /// \param tendonSlackLength The tendon slack length
    /// \param pennAngle The angle of pennation
    /// \param emgMax Maximal excitation and activation of the muscle
    /// \param fatigueParameters The fatigue model
    /// \param torqueAct Time activation constant (default: 0.01)
    /// \param torqueDeact Time deactivation constant (default: 0.04)
    /// \param minAct Minimal activation (default: 0.01)
    ///
    Characteristics(
            biorbd::utils::Scalar optLength,
            biorbd::utils::Scalar fmax,
            biorbd::utils::Scalar PCSA,
            biorbd::utils::Scalar tendonSlackLength,
            double pennAngle,
            const biorbd::muscles::State& emgMax,
            const biorbd::muscles::FatigueParameters& fatigueParameters,
            double torqueAct = 0.01,
            double torqueDeact = 0.04,
            double minAct = 0.01);

    ///
    /// \brief Destroy the class properly
    ///
    virtual ~Characteristics();

    ///
    /// \brief Deep copy of characteristics
    /// \return A depp copy of characteristics
    ///
    biorbd::muscles::Characteristics DeepCopy() const;

    ///
    /// \brief Deep copy of characteristics from another characteristics 
    /// \param other The characteristics to copy from
    ///
    void DeepCopy(
            const biorbd::muscles::Characteristics& other);


    ///
    /// \brief Set the length without tension
    /// \param val Value of the length without tension
    ///
    void setOptimalLength(biorbd::utils::Scalar val);

    ///
    /// \brief Return the optimal length at which maximal force occurs
    /// \return The length without tension
    ///
    virtual biorbd::utils::Scalar optimalLength() const;

    ///
    /// \brief Set the maximal isometric force
    /// \param val Value of the maximal isometric force
    ///
    virtual void setForceIsoMax(biorbd::utils::Scalar val);

    ///
    /// \brief Return the maximal isometric force at optimal length
    /// \return The maximal isometric force
    ///    
    biorbd::utils::Scalar forceIsoMax() const;

    ///
    /// \brief Set the tendon slack length
    /// \param val Value of the tendon slack length
    ///
    void setTendonSlackLength(biorbd::utils::Scalar val);
    ///
    /// \brief Return the tendon slack length
    /// \return The tendon slack length
    ///  
    biorbd::utils::Scalar tendonSlackLength() const;

    ///
    /// \brief Set the angle of pennation
    /// \param val Value of the angle of pennation
    ///
    void setPennationAngle(double val);
    ///
    /// \brief Return the angle of pennation
    /// \return The angle of pennation
    /// 
    double pennationAngle() const;

    ///
    /// \brief Set the physiological cross-sectional area of the muscle
    /// \param val Value of the physiological cross-sectional area of the muscle
    ///
    void setPCSA(biorbd::utils::Scalar val);

    ///
    /// \brief Return the physiological cross-sectional area of the muscle 
    /// \return The physiological cross-sectional area of the muscle 
    ///
    biorbd::utils::Scalar PCSA() const;

    ///
    /// \brief Set the minimal activation of the muscle
    /// \param val The value of the minimal activation of the muscle
    ///
    void setMinActivation(double val);

    ///
    /// \brief Return the minimal activation of the muscle
    /// \return The minimal activation of the muscle
    ///
    biorbd::utils::Scalar minActivation() const;

    ///
    /// \brief Set the time activation constant
    /// \param val The value of the time activation constant 
    ///
    void setTorqueActivation(double val);

    ///
    /// \brief Return the time activation constant
    /// \return The time activation constant
    ///
    double torqueActivation() const;
    
    ///
    /// \brief Set the time deactivation constant
    /// \param val The value of the time deactivation constant
    ///
    void setTorqueDeactivation(double val);

    ///
    /// \brief Return the time deactivation constant
    /// \return The time deactivation constant
    ///
    double torqueDeactivation() const;

    ///
    /// \brief Set the maximal excitation and activation of the muscle
    /// \param emgMax Value of the maximal excitation and activation of the muscle
    ///
    void setStateMax(
            const biorbd::muscles::State &emgMax);

    ///
    /// \brief Return the maximal excitation and activation of the muscle
    /// \return The maximal excitation and activation of the muscle
    ///
    const biorbd::muscles::State& stateMax() const;

    ///
    /// \brief Set the fatigue parameters
    /// \param fatigueParameters The values of the fatigue parameters
    ///
    void setFatigueParameters(
            const biorbd::muscles::FatigueParameters& fatigueParameters);
    ///
    /// \brief Return the fatigue parameters
    /// \return The fatigue parameters
    ///
    const biorbd::muscles::FatigueParameters& fatigueParameters() const;

protected:
    std::shared_ptr<biorbd::utils::Scalar> m_optimalLength; ///< Length without tension
    std::shared_ptr<biorbd::utils::Scalar> m_fIsoMax;       ///< Maximal isometric force Force maximale isométrique
    std::shared_ptr<biorbd::utils::Scalar> m_PCSA;          ///< Physiological cross-sectional area of the muscle
    std::shared_ptr<biorbd::utils::Scalar> m_tendonSlackLength; ///< Tendon slack length
    std::shared_ptr<double> m_pennationAngle; ///< Angle of pennation
    std::shared_ptr<biorbd::muscles::State> m_stateMax; ///< Maximal excitation et activation of the muscle

    // Parametre d'activation
    std::shared_ptr<double> m_minActivation; ///< Minimal activation 
    std::shared_ptr<double> m_torqueActivation; ///<  Time activation constant
    std::shared_ptr<double> m_torqueDeactivation; ///< Time deactivation constant

    // Fatigue parameters
    std::shared_ptr<biorbd::muscles::FatigueParameters> m_fatigueParameters; ///< Fatigue parameters
};

}}

#endif // BIORBD_MUSCLES_CHARACTERISTICS_H
