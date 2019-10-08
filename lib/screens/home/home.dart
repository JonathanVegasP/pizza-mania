import 'package:flutter/material.dart';
import 'package:pizzamania/blocs/home_bloc.dart';
import 'package:pizzamania/resources/images.dart';
import 'package:pizzamania/widgets/animated_button.dart';
import 'package:pizzamania/widgets/dismiss_keyboard.dart';
import 'package:pizzamania/widgets/responsive_widget.dart';
import 'package:provider/provider.dart';

class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    final bloc = Provider.of<HomeBloc>(context);
    return DismissKeyboard(
      child: ResponsiveWidget(
        builder: (type, constraints) {
          bloc.type = type;
          bloc.constraints = constraints;
          return Scaffold(
            resizeToAvoidBottomInset: false,
            body: Container(
              decoration: BoxDecoration(
                gradient: LinearGradient(
                  colors: [
                    Color(0xFFFF512F),
                    Color(0xFFF09819),
                  ],
                ),
              ),
              child: SingleChildScrollView(
                child: ConstrainedBox(
                  constraints: BoxConstraints(
                    minHeight: constraints.maxHeight,
                    minWidth: constraints.maxWidth,
                  ),
                  child: AnimatedPadding(
                    duration: Duration(milliseconds: 500),
                    padding: EdgeInsets.symmetric(
                        horizontal: type == ResponsiveType.LARGE
                            ? constraints.maxWidth * 0.25
                            : constraints.maxWidth * 0.1,
                        vertical: constraints.maxHeight * 0.1),
                    child: Card(
                      child: AnimatedPadding(
                        duration: Duration(milliseconds: 500),
                        padding: EdgeInsets.all(32),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.stretch,
                          children: <Widget>[
                            Align(
                              alignment: Alignment.center,
                              child: Image.asset(
                                LogoImage,
                                height: 75,
                              ),
                            ),
                            Text(
                              "Pizzamania",
                              style: TextStyle(
                                color: Colors.yellow,
                                fontWeight: FontWeight.bold,
                                fontSize: 32.0,
                              ),
                              textAlign: TextAlign.center,
                            ),
                            SizedBox(
                              height: 40.0,
                            ),
                            TextField(
                              decoration: InputDecoration(
                                labelText: "Matrícula",
                                border: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(32.0),
                                ),
                                enabledBorder: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(32.0),
                                  borderSide: BorderSide(color: Colors.red),
                                ),
                              ),
                            ),
                            SizedBox(
                              height: 16,
                            ),
                            TextField(
                              obscureText: true,
                              decoration: InputDecoration(
                                labelText: "Senha",
                                border: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(32.0),
                                ),
                                enabledBorder: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(32.0),
                                  borderSide: BorderSide(color: Colors.red),
                                ),
                              ),
                            ),
                            SizedBox(
                              height: 16.0,
                            ),
                            Align(
                              alignment: Alignment.center,
                              child: AnimatedButton(
                                animation: (animation) {
                                  bloc.animation = animation;
                                },
                                onPressed: () => bloc.animation(),
                                child: Text("Entrar".toUpperCase()),
                                color: Colors.red,
                                width: constraints.maxWidth,
                              ),
                            )
                          ],
                        ),
                      ),
                    ),
                  ),
                ),
              ),
            ),
          );
        },
      ),
    );
  }
}
