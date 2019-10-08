import 'package:flutter/material.dart';

enum ResponsiveType { SMALL, MEDIUM, LARGE }

class ResponsiveWidget extends StatelessWidget {
  final Widget Function(ResponsiveType, BoxConstraints) builder;

  const ResponsiveWidget({
    Key key,
    this.builder,
  }) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return LayoutBuilder(
      builder: (context, constraints) {
        ResponsiveType type;
        if (constraints.maxWidth >= 1280)
          type = ResponsiveType.LARGE;
        else if (constraints.maxWidth >= 768)
          type = ResponsiveType.MEDIUM;
        else
          type = ResponsiveType.SMALL;
        return builder(type, constraints);
      },
    );
  }
}
