/*
 * recipe.cpp is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <vector>
#include <vector>
#include <iostream>
#include "xmlnode.h"
#include "stringparsing.h"
#include "recipe.h"
#include "style.h"
#include "misc.h"
#include "mash.h"
#include "hop.h"
#include "fermentable.h"
#include "equipment.h"
#include "yeast.h"
#include "water.h"

std::string Recipe::toXml()
{
   unsigned int i, size;
   std::string ret = "<RECIPE>\n";
   
   ret += "<NAME>"+name+"</NAME>\n";
   ret += "<VERSION>"+intToString(version)+"</VERSION>\n";
   ret += "<TYPE>"+type+"</TYPE>\n";
   ret += "<BREWER>"+brewer+"</BREWER>\n";
   ret += style->toXml();
   ret += "<BATCH_SIZE>"+doubleToString(batchSize_l)+"</BATCH_SIZE>\n";
   ret += "<BOIL_SIZE>"+doubleToString(boilSize_l)+"</BOIL_SIZE>\n";
   ret += "<BOIL_TIME>"+doubleToString(boilTime_min)+"</BOIL_TIME>\n";
   ret += "<EFFICIENCY>"+doubleToString(efficiency_pct)+"</EFFICIENCY>\n";
   ret += "<HOPS>\n"; size = hops.size();
   for(i = 0; i < size; ++i )
      ret += hops[i]->toXml();
   ret += "</HOPS>\n";
   ret += "<FERMENTABLES>\n"; size = fermentables.size();
   for(i = 0; i < size; ++i )
      ret += fermentables[i]->toXml();
   ret += "</FERMENTABLES>\n";
   ret += "<MISCS>\n"; size = miscs.size();
   for( i = 0; i < size; ++i )
      ret += miscs[i]->toXml();
   ret += "</MISCS>\n";
   ret += "<YEASTS>\n"; size = yeasts.size();
   for( i = 0; i < size; ++i )
      ret += yeasts[i]->toXml();
   ret += "</YEASTS>\n";
   ret += "<WATERS>\n"; size = waters.size();
   for( i = 0; i < size; ++i )
      ret += waters[i]->toXml();
   ret += "</WATERS>\n";
   ret += mash->toXml();
   
   ret += "<ASST_BREWER>"+asstBrewer+"</ASST_BREWER>\n";
   ret += equipment->toXml();
   ret += "<NOTES>"+notes+"</NOTES>\n";
   ret += "<TASTE_NOTES>"+tasteNotes+"</TASTE_NOTES>\n";
   ret += "<TASTE_RATING>"+doubleToString(tasteRating)+"</TASTE_RATING>\n";
   ret += "<OG>"+doubleToString(og)+"</OG>\n";
   ret += "<FG>"+doubleToString(fg)+"</FG>\n";
   ret += "<FERMENTATION_STAGES>"+intToString(fermentationStages)+"</FERMENTATION_STAGES>\n";
   ret += "<PRIMARY_AGE>"+doubleToString(primaryAge_days)+"</PRIMARY_AGE>\n";
   ret += "<PRIMARY_TEMP>"+doubleToString(primaryTemp_c)+"</PRIMARY_TEMP>\n";
   ret += "<SECONDARY_AGE>"+doubleToString(secondaryAge_days)+"</SECONDARY_AGE>\n";
   ret += "<SECONDARY_TEMP>"+doubleToString(secondaryTemp_c)+"</SECONDARY_TEMP>\n";
   ret += "<TERTIARY_AGE>"+doubleToString(tertiaryAge_days)+"</TERTIARY_AGE>\n";
   ret += "<TERTIARY_TEMP>"+doubleToString(tertiaryTemp_c)+"</TERTIARY_TEMP>\n";
   ret += "<AGE>"+doubleToString(age_days)+"</AGE>\n";
   ret += "<AGE_TEMP>"+doubleToString(ageTemp_c)+"</AGE_TEMP>\n";
   ret += "<DATE>"+date+"</DATE>\n";
   ret += "<CARBONATION>"+doubleToString(carbonation_vols)+"</CARBONATION>\n";
   ret += "<FORCED_CARBONATION>"+boolToString(forcedCarbonation)+"</FORCED_CARBONATION>\n";
   ret += "<PRIMING_SUGAR_NAME>"+primingSugarName+"</PRIMING_SUGAR_NAME>\n";
   ret += "<CARBONATION_TEMP>"+doubleToString(carbonationTemp_c)+"</CARBONATION_TEMP>\n";
   ret += "<PRIMING_SUGAR_EQUIV>"+doubleToString(primingSugarEquiv)+"</PRIMING_SUGAR_EQUIV>\n";
   ret += "<KEG_PRIMING_FACTOR>"+doubleToString(kegPrimingFactor)+"</KEG_PRIMING_FACTOR>\n";
   
   ret += "</RECIPE>\n";
   return ret;
}

//=================================CONSTRUCTORS=================================
void Recipe::setDefaults()
{
   name = "";
   type = "";
   brewer = "";
   style = NULL;
   batchSize_l = 0.0;
   boilSize_l = 0.0;
   boilTime_min = 0.0;
   efficiency_pct = 0.0;
   hops = std::vector<Hop*>();
   fermentables = std::vector<Fermentable*>();
   miscs = std::vector<Misc*>();
   yeasts = std::vector<Yeast*>();
   waters = std::vector<Water*>();
   mash = NULL;

   asstBrewer = "";
   equipment = NULL;
   notes = "";
   tasteNotes = "";
   tasteRating = 0.0;
   og = 0.0;
   fg = 0.0;
   fermentationStages = 0;
   primaryAge_days = 0.0;
   primaryTemp_c = 0.0;
   secondaryAge_days = 0.0;
   secondaryTemp_c = 0.0;
   tertiaryAge_days = 0.0;
   tertiaryTemp_c = 0.0;
   age_days = 0.0;
   ageTemp_c = 0.0;
   date = "";
   carbonation_vols = 0.0;
   forcedCarbonation = false;
   primingSugarName = "";
   carbonationTemp_c = 0.0;
   primingSugarEquiv = 0.0;
   kegPrimingFactor = 0.0;
}

Recipe::Recipe()
{
   setDefaults();
}

Recipe::Recipe(const XmlNode *node)
{
   std::vector<XmlNode *> children;
   std::vector<XmlNode *> tmpVec;
   std::string tag;
   std::string leafText;
   XmlNode* leaf;
   unsigned int i, childrenSize;
   bool hasName=false, hasVersion=false, hasGrainTemp=false, hasMashStep=false;
   
   setDefaults();
   
   if( node->getTag() != "RECIPE" )
      throw RecipeException("initializer not passed a RECIPE node.");
   
   node->getChildren( children );
   childrenSize = children.size();
   
   for( i = 0; i < childrenSize; ++i )
   {
      tag = children[i]->getTag();
      children[i]->getChildren( tmpVec );
      
      if( tmpVec.size() == 0 )
         throw RecipeException("Tag \""+tag+"\" has no children.");

      leaf = tmpVec[0]; // May not really be a leaf.
      if( leaf->isLeaf() )
         leafText = leaf->getLeafText();

      if( tag == "NAME" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setName(leafText);
      }
      else if( tag == "VERSION" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         if( parseInt(leafText) != version )
            std::cerr << "Warning: XML RECIPE version is not " << version << std::endl;
         hasVersion=true;
      }
      else if( tag == "TYPE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setType(leafText);
      }
      else if( tag == "BREWER" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setBrewer(leafText);
      }
      else if( tag == "STYLE" )
      {
         style = new Style(children[i]);
      }
      else if( tag == "BATCH_SIZE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setBatchSize_l(parseDouble(leafText));
      }
      else if( tag == "BOIL_SIZE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setBoilSize_l(parseDouble(leafText));
      }
      else if( tag == "BOIL_TIME" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setBoilTime_min(parseDouble(leafText));
      }
      else if( tag == "EFFICIENCY" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setEfficiency_pct(parseDouble(leafText));
      }
      else if( tag == "HOPS" )
      {
         Hop *h;
         unsigned int j;
         
         for( j = 0; j < tmpVec.size(); ++j )
         {
            h = new Hop(tmpVec[j]);
            hops.push_back(h);
         }
      }
      else if( tag == "FERMENTABLES" )
      {
         unsigned int j;
         
         for( j = 0; j < tmpVec.size(); ++j )
            fermentables.push_back(new Fermentable(tmpVec[j]));
      }
      else if( tag == "MISCS" )
      {
         unsigned int j;
         
         for( j = 0; j < tmpVec.size(); ++j )
            miscs.push_back(new Misc(tmpVec[j]));
      }
      else if( tag == "YEASTS" )
      {
         unsigned int j;
         
         for( j = 0; j < tmpVec.size(); ++j )
            yeasts.push_back(new Yeast(tmpVec[j]));
      }
      else if( tag == "WATERS" )
      {
         unsigned int j;
         
         for( j = 0; j < tmpVec.size(); ++j )
            waters.push_back(new Water(tmpVec[j]));
      }
      else if( tag == "MASH" )
      {
         mash = new Mash(children[i]);
      }
      else if( tag == "ASST_BREWER" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setAsstBrewer(leafText);
      }
      else if( tag == "EQUIPMENT" )
      {
         equipment = new Equipment(children[i]);
      }
      else if( tag == "NOTES" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setNotes(leafText);
      }
      else if( tag == "TASTE_NOTES" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setTasteNotes(leafText);
      }
      else if( tag == "TASTE_RATING" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setTasteRating(parseDouble(leafText));
      }
      else if( tag == "OG" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setOg(parseDouble(leafText));
      }
      else if( tag == "FG" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setFg(parseDouble(leafText));
      }
      else if( tag == "FERMENTATION_STAGES" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setFermentationStages(parseInt(leafText));
      }
      else if( tag == "PRIMARY_AGE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setPrimaryAge_days(parseDouble(leafText));
      }
      else if( tag == "PRIMARY_TEMP" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setPrimaryTemp_c(parseDouble(leafText));
      }
      else if( tag == "SECONDARY_AGE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setSecondaryAge_days(parseDouble(leafText));
      }
      else if( tag == "SECONDARY_TEMP" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setSecondaryTemp_c(parseDouble(leafText));
      }
      else if( tag == "TERTIARY_AGE")
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setTertiaryAge_days(parseDouble(leafText));
      }
      else if( tag == "TERTIARY_TEMP" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setTertiaryTemp_c(parseDouble(leafText));
      }
      else if( tag == "AGE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setAge_days(parseDouble(leafText));
      }
      else if( tag == "AGE_TEMP" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setAgeTemp_c(parseDouble(leafText));
      }
      else if( tag == "DATE" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setDate(leafText);
      }
      else if( tag == "CARBONATION" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setCarbonation_vols(parseDouble(leafText));
      }
      else if( tag == "FORCED_CARBONATION" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setForcedCarbonation(parseBool(leafText));
      }
      else if( tag == "PRIMING_SUGAR_NAME" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setPrimingSugarName(leafText);
      }
      else if( tag == "CARBONATION_TEMP" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setCarbonationTemp_c(parseDouble(leafText));
      }
      else if( tag == "PRIMING_SUGAR_EQUI" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setPrimingSugarEquiv(parseDouble(leafText));
      }
      else if( tag == "KEG_PRIMING_FACTOR" )
      {
         if( !leaf->isLeaf())
            throw RecipeException("expected a leaf");
         setKegPrimingFactor(parseDouble(leafText));
      }
      else
         std::cerr << "Warning: unsupported RECIPE tag: " << tag << std::endl;
   }// end for()
} // end Recipe()

//================================"SET" METHODS=================================
void Recipe::setName( const std::string &var )
{
   name = std::string(var);
}

void Recipe::setType( const std::string &var )
{
   if( ! isValidType(var) )
      throw RecipeException("not a valid type: " + var );
   else
   {
      type = std::string(var);
      hasChanged();
   }
}

void Recipe::setBrewer( const std::string &var )
{
   brewer = std::string(var);
   hasChanged();
}

void Recipe::setStyle( Style *var )
{
   if( var == NULL )
      throw RecipeException("null pointer for setStyle");
   else
   {
      style = var;
      hasChanged();
   }
}

void Recipe::setBatchSize_l( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      batchSize_l = var;
      hasChanged();
   }
}

void Recipe::setBoilSize_l( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      boilSize_l = var;
      hasChanged();
   }
}

void Recipe::setBoilTime_min( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      boilTime_min = var;
      hasChanged();
   }
}

void Recipe::setEfficiency_pct( double var )
{
   if( var < 0.0  || var > 100.0 )
      throw RecipeException("invalid percent");
   else
   {
      efficiency_pct = var;
      hasChanged();
   }
}

void Recipe::addHop( Hop *var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      hops.push_back(var);
      hasChanged();
   }
}

void Recipe::addFermentable( Fermentable* var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      fermentables.push_back(var);
      hasChanged();
   }
}
void Recipe::addMisc( Misc* var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      miscs.push_back(var);
      hasChanged();
   }
}

void Recipe::addYeast( Yeast* var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      yeasts.push_back(var);
      hasChanged();
   }
}

void Recipe::addWater( Water* var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      waters.push_back(var);
      hasChanged();
   }
}

void Recipe::setMash( Mash *var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      mash = var;
      hasChanged();
   }
}


void Recipe::setAsstBrewer( const std::string &var )
{
   asstBrewer = std::string(var);
   hasChanged();
}

void Recipe::setEquipment( Equipment *var )
{
   if( var == NULL )
      throw RecipeException("null object");
   else
   {
      equipment = var;
      hasChanged();
   }
}

void Recipe::setNotes( const std::string &var )
{
   notes = std::string(var);
   hasChanged();
}

void Recipe::setTasteNotes( const std::string &var )
{
   tasteNotes = std::string(var);
   hasChanged();
}

void Recipe::setTasteRating( double var )
{
   if( var < 0.0 || var > 50.0 )
      throw RecipeException("bad taste rating: " + doubleToString(var) );
   else
   {
      tasteRating = var;
      hasChanged();
   }
}

void Recipe::setOg( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      og = var;
      hasChanged();
   }
}

void Recipe::setFg( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      fg = var;
      hasChanged();
   }
}

void Recipe::setFermentationStages( int var )
{
   if( var < 0 )
      throw RecipeException("negative quantity");
   else
   {
      fermentationStages = var;
      hasChanged();
   }
}

void Recipe::setPrimaryAge_days( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      primaryAge_days = var;
      hasChanged();
   }
}

void Recipe::setPrimaryTemp_c( double var )
{
   primaryTemp_c = var;
   hasChanged();
}

void Recipe::setSecondaryAge_days( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      secondaryAge_days = var;
      hasChanged();
   }
}

void Recipe::setSecondaryTemp_c( double var )
{
   secondaryTemp_c = var;
   hasChanged();
}

void Recipe::setTertiaryAge_days( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      tertiaryAge_days = var;
      hasChanged();
   }
}

void Recipe::setTertiaryTemp_c( double var )
{
   tertiaryTemp_c = var;
   hasChanged();
}

void Recipe::setAge_days( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      age_days = var;
      hasChanged();
   }
}

void Recipe::setAgeTemp_c( double var )
{
   ageTemp_c = var;
   hasChanged();
}

void Recipe::setDate( const std::string &var )
{
   date = std::string(var);
   hasChanged();
}

void Recipe::setCarbonation_vols( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      carbonation_vols = var;
      hasChanged();
   }
}

void Recipe::setForcedCarbonation( bool var )
{
   forcedCarbonation = var;
   hasChanged();
}

void Recipe::setPrimingSugarName( const std::string &var )
{
   primingSugarName = std::string(var);
   hasChanged();
}

void Recipe::setCarbonationTemp_c( double var )
{
   carbonationTemp_c = var;
   hasChanged();
}

void Recipe::setPrimingSugarEquiv( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      primingSugarEquiv = var;
      hasChanged();
   }
}

void Recipe::setKegPrimingFactor( double var )
{
   if( var < 0.0 )
      throw RecipeException("negative quantity");
   else
   {
      kegPrimingFactor = var;
      hasChanged();
   }
}

//=============================="GET" METHODS===================================
std::string Recipe::getName() const
{
   return name;
}

std::string Recipe::getType() const
{
   return type;
}

std::string Recipe::getBrewer() const
{
   return brewer;
}

Style* Recipe::getStyle() const
{
   return style;
}

double Recipe::getBatchSize_l() const
{
   return batchSize_l;
}

double Recipe::getBoilSize_l() const
{
   return boilSize_l;
}

double Recipe::getBoilTime_min() const
{
   return boilTime_min;
}

double Recipe::getEfficiency_pct() const
{
   return efficiency_pct;
}

unsigned int Recipe::getNumHops() const
{
   return hops.size();
}

Hop* Recipe::getHop(unsigned int i)
{
   if( i >= hops.size() )
      throw RecipeException("bad index: " + intToString(i) );
   else
      return hops[i];
}

unsigned int Recipe::getNumFermentables() const
{
   return fermentables.size();
}

Fermentable* Recipe::getFermentable(unsigned int i)
{
   if( i >= fermentables.size() )
      throw RecipeException("bad index: " + intToString(i) );
   return fermentables[i];
}

unsigned int Recipe::getNumMiscs() const
{
   return miscs.size();
}

Misc* Recipe::getMisc(unsigned int i)
{
   if( i >= miscs.size() )
      throw RecipeException("bad index: " + intToString(i) );
   return miscs[i];
}

unsigned int Recipe::getNumYeasts() const
{
   return yeasts.size();
}

Yeast* Recipe::getYeast(unsigned int i)
{
   if( i >= yeasts.size() )
      throw RecipeException("bad index: " + intToString(i) );
   return yeasts[i];
}

unsigned int Recipe::getNumWaters() const
{
   return waters.size();
}

Water* Recipe::getWater(unsigned int i)
{
   if( i >= waters.size() )
      throw RecipeException("bad index: " + intToString(i) );
   return waters[i];
}

Mash* Recipe::getMash() const
{
   return mash;
}

std::string Recipe::getAsstBrewer() const
{
   return asstBrewer;
}

Equipment* Recipe::getEquipment() const
{
   return equipment;
}

std::string Recipe::getNotes() const
{
   return notes;
}

std::string Recipe::getTasteNotes() const
{
   return tasteNotes;
}

double Recipe::getTasteRating() const
{
   return tasteRating;
}

double Recipe::getOg() const
{
   return og;
}

double Recipe::getFg() const
{
   return fg;
}

int Recipe::getFermentationStages() const
{
   return fermentationStages;
}

double Recipe::getPrimaryAge_days() const
{
   return primaryAge_days;
}

double Recipe::getPrimaryTemp_c() const
{
   return primaryTemp_c;
}

double Recipe::getSecondaryAge_days() const
{
   return secondaryAge_days;
}

double Recipe::getSecondaryTemp_c() const
{
   return secondaryTemp_c;
}

double Recipe::getTertiaryAge_days() const
{
   return tertiaryAge_days;
}

double Recipe::getTertiaryTemp_c() const
{
   return tertiaryTemp_c;
}

double Recipe::getAge_days() const
{
   return age_days;
}

double Recipe::getAgeTemp_c() const
{
   return ageTemp_c;
}

std::string Recipe::getDate() const
{
   return date;
}

double Recipe::getCarbonation_vols() const
{
   return carbonation_vols;
}

bool Recipe::getForcedCarbonation() const
{
   return forcedCarbonation;
}

std::string Recipe::getPrimingSugarName() const
{
   return primingSugarName;
}

double Recipe::getCarbonationTemp_c() const
{
   return carbonationTemp_c;
}

double Recipe::getPrimingSugarEquiv() const
{
   return primingSugarEquiv;
}

double Recipe::getKegPrimingFactor() const
{
   return kegPrimingFactor;
}

bool Recipe::isValidType( const std::string &str )
{
   static const std::string types[] = {"Extract", "Partial Mash", "All Grain"};
   static const unsigned int size = 3;
   unsigned int i;
   
   for( i = 0; i < size; ++i )
      if( str == types[i] )
         return true;
   
   return false;
}
