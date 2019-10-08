import 'package:flutter/material.dart';

class DismissKeyboard extends StatelessWidget {
  final Widget child;

  const DismissKeyboard({Key key, this.child}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: FocusScope.of(context).unfocus,
      child: child,
    );
  }
}
