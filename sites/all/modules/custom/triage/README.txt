-- SUMMARY --

The Triage module adds a guided pathway option for navigating 
content on your site. Site administrators can create a Logic Tree 
to help site users quickly find answers to specific questions. 
Administrators can create layered and question sqpecific content 
for that question, as well as referencing other site content and 
common re-usable text. Content can be assembled selectively 
based on county, status info (senior, handicapped, veteran, etc) 
and income information. 

For full documentation, go to http://bdsworks.org/triage-text-doc

INSTALL THE TRIAGE EXAMPLE MODULE to get a complete working Legal Service Triage,
based on Pine Tree Legal's Logic Tree, 
see http://bdsworks.org/quick-look-around-triage-example

-- REQUIREMENTS --

 term_reference_tree
 htmLawed
 ctools
 i18n
 features 	 
 uuid
 uuid_features
 taxonomy_manager
 variable
 i18n_node
 date
 triage-actions

In addition, you will want an HTML email module such as mimemail or htmlmail

-- INSTALLATION --

* Install as usual, see http://drupal.org/node/895232 for further information.

* You likely want to disable Toolbar module, since its output clashes with
  Administration menu.

-- CONFIGURATION --

To set up a working Triage Logic Tree:

1. Create a hierarchical taxonomy, breaking down issues.  Use the Taxonomy Manager 
to add the terms, as you'll be able to add multiple terms easily.  Here's an example
of terms to add:

    Automobiles
    -My car won't start
    --The engine doesn't turn at all when I turn the key
    --The engine turns over but doesn't catch
    --The engine starts but dies as soon as I try to go into gear
    -There's blue smoke coming out the tailpipe
    Electricty
    -My lights went out
    --The lights are on in another room
    --The lights are out in every room
    ---My neighbors lights seem to be on
    ---My neighbors lights are out, too

2. From the Content Menu, Add Content->Triage Page.  
    Fill in the title and Save.   
    Select your logic tree taxonomy from the Triage Configuration tab.
    Your new triage is available at http://yousite.com/triage/your_taxonomy
        where your_taxonomy is the machine name of the logic tree taxonomy
    
    Documentation on additional configuration options is available 

-- CONTACT --

Brian Dyer Stewart, current maintainer
brian@bdsworks.org

This project was sponsored by the Legal Services Corporation and
was developed collaboratively among three New England States and their
legal service providers:
    Connecticut Legal Services http://ctlawhelp.org
    Pine Tree Legal Services http://ptla.org
    Vermont Legal Aid http://vtlawhelp.org