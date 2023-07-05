RTHawk Plugin Readme

To create a new RTHawk plugin,

1.  Copy the `/usr/share/RthReconstruction/example/scriptPluginExample` directory and its contents to a new folder under your home directory:
    ```
    cp -r /usr/share/RthReconstruction/example/scriptPluginExample ~/wroScriptPlugin
    cd ~/wroScriptPlugin
    ```
2.  This directory contains a class to register your class(es) with JavaScript (`RthReconCustomScriptPlugin`) and a class to implement an example recon node (`RthReconCustomFilter`).  We will rename both.
     * 2a.  Rename the files that register your class(es) with JavaScript.  As a prefix, use your initials or your institution's initials instead of "Rth".  For example,
    ``` 
    mv RthReconCustomScriptPlugin.cpp WROScriptPlugin.cpp
    mv RthReconCustomScriptPlugin.h WROScriptPlugin.h
    mv RthReconCustomScriptPlugin.json WROScriptPlugin.json
    ```
     * 2b.  Rename the files for the example class to your new class name.  As a prefix, use your initials or your institution's initials instead of `Rth`. For example,
    ``` 
    mv RthReconCustomFilter.cpp WROSparseTransform.cpp
    mv RthReconCustomFilter.h WROSparseTransform.h
    ```
3.  Change all of the references to `RthReconCustomScriptPlugin` and `RthReconCustomFilter` to your new names.  These commands could help:
    ```
    sed -i -e "s/RthReconCustomScriptPlugin/WROScriptPlugin/g" *.*
    sed -i -e "s/RthReconCustomFilter/WROSparseTransform/g" *.*
    ```
4.  Also change this line in the `WROScriptPlugin.h` file:

    * **old:**  `Q_PLUGIN_METADATA(IID "com.heartvista.rthawk.rthreconcustomscriptplugin" FILE "WROScriptPlugin.json")`
    * **new:**  `Q_PLUGIN_METADATA(IID "edu.yourinstitution.wro.scriptplugin" FILE "WROScriptPlugin.json")`

5.  Update the extension name to be imported in your JavaScript from `rth.customRecon` to your own thing.
    ```
    sed -i -e "s/rth.customRecon/wro.scriptPlugin/g" *.*
    sed -i -e "s/\"rth/\"wro/g" *.*
    ```
6.  Make a new build directory, enter it, configure the build, make the plugin, install it:
    ```
    mkdir build
    cd build
    cmake ..
    make -j4
    make install
    ```
7.  Import your new plugin into your .js:
    (JavaScript)
    ```
    // To load the custom plugin:
    qt.script.importExtension("wro.scriptPlugin");
    ```
    ```
    // Then the script can freely use the custom module:
    var sparseTransform = new WROSparseTransform();
    sparseTransform.setWidth(0.48);
    ```

    // Parameters can also be set as object members:
    sparseTransform.radius = 0.02;
