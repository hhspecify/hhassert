<?hh //strict

namespace hhassert\matcher;

final class Value
{

    public function __construct(
        private mixed $value,
        private bool $wrap = true
    )
    {
    }

    public static function of(mixed $value) : Value
    {
        return new Value($value);
    }

    public function unwrap() : this
    {
        $this->wrap = false;
        return $this;
    }

    public function __toString() : string
    {
        if (is_null($this->value)) {
            $value = 'null';
        } else if (is_bool($this->value)) {
            $value = $this->value ? 'true' : 'false';
        } else if (is_string($this->value)) {
            $value = $this->wrap ?  "'" . $this->value . "'" : $this->value;
        } else {
            $value = rtrim(print_r($this->value, true));
        }

        return $value;
    }

}
