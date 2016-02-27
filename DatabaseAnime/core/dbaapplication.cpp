#include "dbaapplication.h"

#include <QIcon>
#include <QSettings>
#include "dbalocalization.h"
#include "definespath.h"

void DbaApplication::setProgramInfo()
{
    setOrganizationName("LibertaSoft");
    setOrganizationDomain("https://github.com/LibertaSoft");
    setApplicationName("DatabaseAnime");
    setApplicationVersion("1.4.2");
    setApplicationDisplayName( QObject::tr("Database Anime") );
    setWindowIcon( QIcon("://images/DBA_Icon.png") );
}

void DbaApplication::loadLocalization()
{
    QLocale locale = settings()->value("Global/Locale").toLocale();

    _qtBaseTranslator.load( DbaLocalization::getQtBaseFileOfLocalization( locale.language(), DefinesPath::share() ) );
    _appTranslator.load( DbaLocalization::getFileOfLocalization( locale.language(), DefinesPath::share() ) );
    installTranslator( & _qtBaseTranslator );
    installTranslator( & _appTranslator );
}

DbaApplication::DbaApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setProgramInfo();
    _settings = new QSettings;
    setLogger( new Logger );
    setLocale( QLocale::system() ); /// \todo read locale from settings
    loadLocalization();
}

DbaApplication::~DbaApplication()
{
    delete _settings;
    delete _logger;
}

void DbaApplication::setLocale(const QLocale &locale)
{
    _locale = locale;
}

QLocale DbaApplication::getLocale()
{
    return _locale;
}

/*! \~russian
 * \brief Метод для установки реализации класса логирования
 * \param logger - право владения объектом, класс берёт на себя.
 */
/*! \~english
 * \brief Method for set Logger implementation
 * \param logger - ownership of an object, the class takes over.
 */
void DbaApplication::setLogger(Logger *logger)
{
    delete _logger;
    _logger = logger;
}

Logger* DbaApplication::logger()
{
    if( ! _logger )
        _logger = new Logger;
    return _logger;
}

QSettings* DbaApplication::settings()
{
    if( ! _settings )
        _settings = new QSettings;

    return _settings;
}
