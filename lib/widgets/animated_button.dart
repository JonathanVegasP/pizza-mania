import 'dart:js';

import 'package:flutter/material.dart';

class AnimatedButton extends StatefulWidget {
  final double width;
  final Function(VoidCallback) animation;
  final VoidCallback onPressed;
  final Widget child;
  final Color textColor;
  final double textSize;
  final Color color;

  const AnimatedButton({
    Key key,
    this.width,
    this.animation,
    this.onPressed,
    this.textColor = Colors.white,
    this.textSize = 16.0,
    this.color = Colors.red,
    this.child,
  }) : super(key: key);
  @override
  _AnimatedButtonState createState() => _AnimatedButtonState();
}

class _AnimatedButtonState extends State<AnimatedButton>
    with SingleTickerProviderStateMixin {
  AnimationController _controller;
  Animation<double> _buttonSqueeze;

  @override
  void initState() {
    _controller = AnimationController(
      vsync: this,
      duration: Duration(milliseconds: 500),
    );
    _buttonSqueeze = Tween<double>(
      begin: widget.width,
      end: 56.0,
    ).animate(
      CurvedAnimation(
        curve: Curves.easeOut,
        parent: _controller,
      ),
    );
    super.initState();
  }

  @override
  void didChangeDependencies() {
    _buttonSqueeze = Tween<double>(
      begin: widget.width,
      end: 56.0,
    ).animate(
      CurvedAnimation(
        curve: Curves.easeOut,
        parent: _controller,
      ),
    );
    widget.animation(_animation);
    super.didChangeDependencies();
  }

  void _animation() {
    if (_controller.isCompleted)
      _controller.reverse();
    else
      _controller.forward();
  }

  @override
  Widget build(BuildContext context) {
    return AnimatedBuilder(
      animation: _buttonSqueeze,
      builder: (context, child) {
        return Material(
          textStyle: TextStyle(
            color: widget.textColor,
            fontSize: widget.textSize,
            fontWeight: FontWeight.bold,
          ),
          color: Colors.transparent,
          child: InkWell(
            borderRadius: BorderRadius.circular(56.0),
            onTap: widget.onPressed,
            child: Ink(
              child: _controller.value <= 0.5
                  ? Center(
                      child: widget.child,
                    )
                  : Center(
                      child: CircularProgressIndicator(
                        valueColor: AlwaysStoppedAnimation<Color>(
                          widget.textColor,
                        ),
                      ),
                    ),
              height: 56.0,
              width: _buttonSqueeze.value,
              decoration: BoxDecoration(
                color: widget.color,
                borderRadius: BorderRadius.circular(56.0),
              ),
            ),
          ),
        );
      },
    );
  }
}
