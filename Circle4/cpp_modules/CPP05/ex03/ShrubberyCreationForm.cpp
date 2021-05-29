#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::mAsciiTree =
    "\
       :                       ..,,..    ...,,..\n\
      ,%,                .. ,#########::#########:,\n\
      :#%%,           ,,:',####%%%%%%##:`::%%%%####,\n\
     ,##%%%%,      ,##%% ,##%%%:::::''%' `::::%%####,\n\
     %###%%;;,   ,###%%:,##%%:::''    '  . .`:::%%###,\n\
    :####%%;;:: ,##%:' ,#%::''   .,,,..    . .`::%%%##,\n\
    %####%;;::,##%:' ,##%''  ,%%########%     . `:::%%##,\n\
    ######:::,##%:',####:  ,##%%:''     `%%,     .`::%%##,\n\
    :#####%:'##%:',#####' ,###%' ,%%%%,%%,'%,     . ::%%###,,..\n\
     #####%:,#%:'#######  %%:'%  %'  `%% %% %%,.     '::%%#######,\n\
     `####%,#%:',####### ::' %   ' ,%%%%%%, ::%%.    . '::%%######\n\
      `###'##%: ######## ,.   %%  %%,   ':: `:%%%  :  . .:::%%###'\n\
      ,,::,###  %%%%%### ::  % %% '%%%,.::: .:%%%   #.  . ::%%%#'\n\
,,,:::%%##:;#   `%%%%%## :% ,%, %   ':%%:'  #%%%' ,.:##.  ::%#'\n\
::%%#####% %%:::  :::%%% `%%,'%%     ..,,%####' :%# `::##, ''\n\
###%%::'###%::: .   `:::, `::,,%%%######%%'',::%##' ,:::%##\n\
''''   ,####%:::. .  `::%,     '':%%::' .,::%%%#'   :::%%%##,\n\
      :#%%'##%:::.  . . \"%::,,.. ..,,,,::%%%###'  ,:%%%%####'\n\
     ,###%%'###%:::: . . `::::::::::%%%#####'   ,::%####:'\n\
     %###%%;'###%::::.   .`::%%%%%%%#####:'  ,,::%%##:'\n\
     ####%;:;'####%:::::.   `:%######::'  ,,:::%%###\n\
     %####;:;'######%%::::.           ,::::%%%####'\n\
     `####%;:'`#########%%:::....,,:::%%%#######'\n\
        ;#####;;'..;;:::#########::%%#########:\"\'\n\
                       ~~~~``````''''~~~\n\
\n\
    ";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreation", 145, 137),
      mTarget(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scForm)
    : Form(scForm), mTarget(scForm.mTarget)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scForm)
{
    mTarget = scForm.mTarget;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    if (Form::getSigned())
    {
        if (bureaucrat.getGrade() <= Form::getExecuteGrade())
        {
            std::ofstream ofs(mTarget + "_shrubbery");

            if (ofs.is_open())
            {
                ofs << mAsciiTree;
                ofs.close();
            }
            else
                throw ShrubberyCreationForm::FileOpenException();
        }
        else
            throw Form::GradeTooLowException();
    }
    else
        throw Form::NotSignedException();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return (ANSI_COLOR_RED "ShrubberyCreationException: File open failed" ANSI_COLOR_RESET);
}