import 'package:flutter/material.dart';
import 'package:flutter_localizations/flutter_localizations.dart';
import 'package:pizzamania/blocs/home_bloc.dart';
import 'package:pizzamania/screens/home/home.dart';
import 'package:provider/provider.dart';

class Pizzamania extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      localizationsDelegates: [
        GlobalMaterialLocalizations.delegate,
        GlobalWidgetsLocalizations.delegate,
      ],
      localeResolutionCallback: (l, s) => l,
      title: "Pizzamania",
      theme: ThemeData(
        primaryColor: Colors.red,
        accentColor: Colors.yellow,
        hintColor: Colors.red,
        cursorColor: Colors.red,
        textSelectionHandleColor: Colors.red,
      ),
      initialRoute: "/",
      routes: {
        "/": (context) => Provider<HomeBloc>(
              builder: (context) => HomeBloc(),
              child: HomeScreen(),
            ),
      },
    );
  }
}

void main() => runApp(Pizzamania());
