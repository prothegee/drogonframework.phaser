#pragma once
// reserved


#include <drogon/drogon.h>




namespace NSBackend
{




class CMain
{
private:
    inline static const std::string m_projectName = "drogonframework-phaser";
    inline static const std::string m_projectVersion = "v1.0.0";




protected:
    /* data */




public:
    CMain(/* args */) = default;
    ~CMain() = default;


    /**
     * @brief log args based on this project on Debug only
     * 
     * @tparam Args 
     * @param args 
     */
    template <class Args>
    static void LogInfo(Args&& args)
    {
        #ifdef NDEBUG
        #else
        std::cout << "-- " << m_projectName << " " << m_projectVersion << ": " << args << "\n";
        #endif
    }


    /**
     * @brief Get the projectName object
     * 
     * @return std::string 
     */
    std::string get_projectName() const
    {
        return m_projectName;
    }


    /**
     * @brief Get the projectVersion object
     * 
     * @return std::string 
     */
    std::string get_projectVersion() const
    {
        return m_projectVersion;
    }
}; // class CMain




} // namespace NSBackend
